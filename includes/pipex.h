/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:44:04 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/20 13:42:24 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_struct
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd_path;
	char 	**cmd_arg;
	char	*cmd;
}	t_struct;

//child.c
void    first_child(t_struct pipex, char **av, char **envp);
void	second_child(t_struct pipex, char **av, char **envp);

//error.c
int 	mess_err(char *err);
void    error(char *err);

//free.c
void	free_child(t_struct *pipex);
void	free_parent(t_struct *pipex);

//main.c
char	*find_path(char **envp);
void	close_pipe(t_struct *pipex);

#endif
