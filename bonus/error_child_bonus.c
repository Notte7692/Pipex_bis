/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:51:59 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/09 15:35:44 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error_full_path(t_pipex *command, char **args, int i)
{
	ft_free_child(command, args, i);
}

void	command_not_found(char *cmd)
{
	char	*str;

	if (cmd != NULL && (cmd[0] == ' ' || !cmd[0]))
	{
		str = ft_strjoin(cmd, ": Command not found");
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		free(str);
	}
	else if (cmd && ft_strchr(cmd, '/') != NULL)
	{
		str = ft_strjoin(cmd, ": No such file or directory \n");
		write (2, str, ft_strlen(str));
		write(2, "\n", 1);
		free(str);
	}
	else
		write(2, "Command not found \n", 19);
}
