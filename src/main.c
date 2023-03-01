/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:23:10 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/01 10:15:12 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc != 5)
	{
		ft_putstr_fd("Error", 2);
		return (1);
	}
	data = init_data(argv, envp);
	if (pipe(data->pipe) < 0)
	{
		ft_putstr_fd("Error pipe\n", 2);
		exit(EXIT_FAILURE);
	}
	cmd1_process(data);
	cmd2_process(data);
	free(data);
	return (0);
}

t_data	*init_data(char **argv, char **envp)
{
	t_data	*data;
	int		fd_1;
	int		fd_2;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error malloc struct\n", 2);
		exit(EXIT_FAILURE);
	}
	fd_1 = open(argv[1], O_RDONLY);
	fd_2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_1 < 0)
		ft_putstr_fd("Error open\n", 2);
	if (fd_2 < 0)
	{
		ft_putstr_fd("Error open\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
	data->argv = argv;
	data->envp = envp;
	data->fd_1 = fd_1;
	data->fd_2 = fd_2;
	data->cmd_1 = ft_split(argv[2], ' ');
	data->cmd_2 = ft_split(argv[3], ' ');
	return (data);
}
