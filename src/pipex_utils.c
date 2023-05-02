/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:17:36 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/02 19:17:39 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	close_fd(int *fd)
{
	if (*fd < 0)
		return (-1);
	if (close(*fd) == -1)
		return (perror("close"), -1);
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
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	**get_command_args(char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	return (args);
}
