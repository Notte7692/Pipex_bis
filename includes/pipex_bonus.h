/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:42:50 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/23 16:47:13 by nassimsalhi      ###   ########.fr       */
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
	char	*env_path;
}	t_struct;

#endif
