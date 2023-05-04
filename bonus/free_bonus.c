/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:35:44 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/04 18:02:33 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_free_child(t_pipex *command, char **args)
{
	if (command->in != 0 && command->in != -1)
		close(command->in);
	if (command->out != 0 && command->in != -1)
		close(command->out);
	if (command->previous_pipes != -1 && command->in != -1)
		close(command->previous_pipes);
	free_tab(args);
	free_tab(command->paths);
	free(command->pids);
	close_fd(command->fds)
	exit(EXIT_FAILURE);
}
