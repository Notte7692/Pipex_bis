/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:06:07 by nsalhi            #+#    #+#             */
/*   Updated: 2023/03/17 14:34:02 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex.h"

void    first_child(t_struct pipex, char **av, char **envp)
{
	dup2(pipex.pipefd[1], 1);
	close(pipex.pipefd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_arg = ft_split(av[2], ' ');
}