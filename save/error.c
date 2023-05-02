/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:25:32 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/04/25 09:58:33 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strlen_mod(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	mess_err(char *err)
{
	write(2, err, ft_strlen_mod(err));
	write(1, "\n", 1);
	return (1);
}

void	error_b(char *err)
{
	perror(err);
	exit (1);
}

int	check_args(char **av, char **envp, int ac)
{
	char	**paths;
	int		i;
	char	*cmd;

	paths = extract_path(envp);
	i = 2;
	while (i < ac -1)
	{
		cmd = get_cmd(paths, av[i]);
		if (cmd == NULL)
		{
			free(cmd);
			free_tab(paths);
			return (0);
		}
		free(cmd);
		i++;
	}
	free_tab(paths);
	return (1);
}
