/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:10 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/01 11:23:40 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path_cmd(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**envp_path;
	int		i;

	i = 0;
	if (!access(cmd, F_OK))
		return (ft_strjoin("", cmd));
	if (*cmd == '/')
		return (NULL);
	envp_path = ft_split(get_envp_path(envp) + 5, ':');
	cmd_path = create_path(cmd, envp_path[i]);
	while (access(cmd_path, F_OK) < 0 && envp_path[i])
	{
		free(cmd_path);
		cmd_path = create_path(cmd, envp_path[i++]);
	}
	if (envp_path[i] == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		free(cmd_path);
		cmd_path = NULL;
	}
	free_tab_char(envp_path);
	return (cmd_path);
}

char	*create_path(char *cmd, char *envp_path)
{
	char	*add_slash;
	char	*path;

	add_slash = ft_strjoin("/", cmd);
	path = ft_strjoin(envp_path, add_slash);
	free(add_slash);
	return (path);
}

char	*get_envp_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		i++;
	return (envp[i]);
}

void	free_tab_char(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	close_all(t_data *data, int fd)
{
	close(data->pipe[0]);
	close(data->pipe[1]);
	close(fd);
}
