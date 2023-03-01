/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:16 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/01 15:01:44 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	cmd1_process(t_data *data)
{
	char	*path_cmd;
	pid_t	pid;

	path_cmd = find_path_cmd(data->cmd_1[0], data->envp);
	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Error pid for command_1\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if ((dup2(data->fd_1, STDIN_FILENO) < 0)
			|| (dup2(data->pipe[1], STDOUT_FILENO) < 0))
		{
			close_all(data, data->fd_1);
			return ;
		}
		close_all(data, data->fd_1);
		execve(path_cmd, data->cmd_1, data->envp);
	}
	waitpid(pid, NULL, 0);
	free_tab_char(data->cmd_1);
	free(path_cmd);
}

void	cmd2_process(t_data *data)
{
	char	*path_cmd;
	pid_t	pid;

	path_cmd = find_path_cmd(data->cmd_2[0], data->envp);
	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Error pid for command_2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if ((dup2(data->fd_2, STDOUT_FILENO) < 0)
			|| (dup2(data->pipe[0], STDIN_FILENO) < 0))
		{
			close_all(data, data->fd_2);
			return ;
		}
		close_all(data, data->fd_2);
		execve(path_cmd, data->cmd_2, data->envp);
	}
	free_tab_char(data->cmd_2);
	free(path_cmd);
}
