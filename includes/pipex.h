/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:44:04 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/15 17:01:50 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"x
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_struct
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd_path;
}	t_struct;

#endif
