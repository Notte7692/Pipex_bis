/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:42:50 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/29 16:36:45 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_struct
{
	pid_t	pid;
    int		infile;
    int		outfile;
	char	**cmd_path;
	char	*cmd;
	char	**cmd_arg;
	int		here_doc;
	int		nb_cmd;
	int		nb_pipe;
	int		*pipe;
	int 	pipe[2];
	char	*env_path;
	int		index;
}	t_struct;

//chidl_bonus.c
void    child(t_struct pipex, char **av, char **envp);

//error_bonus.c
int		msg(char *error);
void	msg_pipe(char *arg);
void	msg_error(char *error);

//free_bonus.c
void    free_pipe(t_struct *pipex);
void    free_parent(t_struct *pipex);
void    free_child(t_struct *pipex);

//get_gile_bonus.c
void	get_infile(char **av, t_struct *pipex);
void	get_outfile(char *av, t_struct *pipex);

//heredoc_bonus.c
void	here_doc(char *av, t_struct *pipex);

//main_bonus.c
int		min_arg(char *av, t_struct *pipex);
char	*find_path(char **envp);
void	close_pipes(t_struct *pipex);

#endif
