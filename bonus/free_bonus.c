/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:35:44 by nsalhi            #+#    #+#             */
/*   Updated: 2023/04/27 18:58:01 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_free_child(t_pipex *command, char **args)
{
	if (command->in != 0)
		close(command->in);
	if (command->out != 0)
		close(command->out);
	if (command->previous_pipes != -1)
		close(command->previous_pipes);
	free_tab(args);
	free_tab(command->paths);
	free(command->pids);
	exit(EXIT_FAILURE);
}

//void    free_here_doc.c