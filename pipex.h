/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:36:08 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/01 11:23:56 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ########## Start ##########

#ifndef PIPEX_H
# define PIPEX_H

// ########## Includes ##########

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

// ########## Structurs ##########

typedef struct s_data
{
	char	**argv;
	char	**envp;
	char	**cmd_1;
	char	**cmd_2;
	int		pipe[2];
	int		fd_1;
	int		fd_2;
}t_data;

// ########## Functions ##########

int		main(int argc, char **argv, char **envp);

char	**get_tab_cmd(char *cmd);
char	*get_envp_path(char **envp);
char	*find_path_cmd(char *cmd, char **envp);
char	*create_path(char *cmd, char *envp_path);

void	free_tab_char(char **tab);
void	cmd1_process(t_data *data);
void	cmd2_process(t_data *data);
void	close_all(t_data *data, int fd);
void	pipex(int fd_1, int fd_2, char **argv, char **envp);

t_data	*init_data(char **argv, char **envp);

// ########## End ##########

#endif
