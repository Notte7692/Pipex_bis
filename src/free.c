/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:27:37 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/19 12:27:39 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_child(t_struct *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_arg[i])
	{
		free(pipex->cmd_arg[i]);
		i++;
	}
	free(pipex->cmd_arg);
	free(pipex->cmd);
}

void	free_parent(t_struct *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while(pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}