/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:33 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/04 18:17:15 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_child(t_pipex *command, char **args)
{
	if (command->in != 0 || command->in != -1)
		close_fd(&command->in);
	if (command->out != 0 || command->out != -1)
		close_fd(&command->out);
	if (command->previous_pipes != -1 && command->previous_pipes != 0)
		close_fd(&command->previous_pipes);
	if (args)
		free_tab(args);
	if (command->paths)
		free_tab(command->paths);
	free(command->pids);
	close_fd(&command->fds[0]);
	close_fd(&command->fds[1]);
	exit(EXIT_FAILURE);
}
