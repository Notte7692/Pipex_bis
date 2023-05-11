/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:08:16 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/11 16:00:52 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	close_fd(int *fd)
{
	if (*fd < 0)
		return (-1);
	if (close(*fd) == -1)
		return (-1);
	*fd = -1;
	return (0);
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

char	**parse_command(char **av, int doc)
{
	if (doc)
		return (&av[3]);
	return (&av[2]);
}

char	*find_path(char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (envp[len])
		len++;
	while (i < len)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			return (*envp + 5);
		envp++;
		i++;
	}
	return (NULL);
}

char	**get_command_args(char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	return (args);
}
