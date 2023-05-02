/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:03 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/02 19:16:09 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_full_path(t_pipex *command, char **args)
{
	write(2, "Command not found :\n", 20);
	ft_free_child(command, args);
	exit (127);
}
