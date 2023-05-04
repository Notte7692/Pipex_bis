/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_child_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:51:59 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/04 10:42:33 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error_full_path(t_pipex *command, char **args)
{
	write(2, "Command not found :\n", 20);
	ft_free_child(command, args);
	exit (127);
}

void	command_not_found(char *cmd)
{
	char	*str;
	
	str = ft_strjoin(cmd, ": Command no found");
	printf("str = %s\n", str); 
	write(2 , &str\n, ft_strlen(cmd) +1);
	free(str);
}