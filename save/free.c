/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:27:37 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/04 17:37:33 by nsalhi           ###   ########.fr       */
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
	close_fd(pipex->infile);
	close_fd(pipex->outfile);
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
