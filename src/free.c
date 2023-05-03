/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:33 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/03 15:47:09 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
