/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:51:59 by nsalhi            #+#    #+#             */
/*   Updated: 2023/04/27 17:25:24 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_full_path(t_pipex *command, char **args)
{
	write(2, "Command not found :\n", 20);
	ft_free_child(command, args);
	exit (127);
}
