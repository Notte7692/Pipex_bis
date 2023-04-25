/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:03:00 by nsalhi            #+#    #+#             */
/*   Updated: 2023/04/25 14:32:38 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus_bis.h"

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

char **extract_path(char **envp)
{
    char *paths;
    char **paths_splitted;

	paths = find_path(envp);
	paths_splitted = ft_split(paths, ':');
    return paths_splitted;
}

char **get_command_args(char *command)
{
	char **args = ft_split(command, ' ');
	return args;
}

static char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;

	if (cmd != NULL && access(cmd, 0) == 0)
		return (cmd);
	while (*cmd_path)
	{
		tmp = ft_strjoin(*cmd_path, "/");
		command = ft_strjoin(tmp, cmd);
		if (command != NULL && access(command, 0) == 0)
		{
			free(tmp);
			return (command);
		}
		free(tmp);
		free(command);
		cmd_path++;
	}
	return (NULL);
}

int	check_args(av, envp, ac)
{
	char	**paths;
	char	**args;
	char	*cmd;
	int		i;
	
	paths = extract_path(envp);
	while (i < ac -1)
	{
		args = get_command_args(av[i]);
		cmd = get_cmd(paths, args[0]);
		if (cmd == 0)
		{
			free(cmd);
			free_tab(paths);
			free_tab(args);
			return (0);
		}
		free_tab(args);
		free(cmd);
		i++;
	}
	free(cmd);
	free_tab(paths);
	free_tab(args);
	return (1);
}

int	check_nb_args(int ac, char **av)
{
	if (!av[1] || (ft_strncmp("here_doc", av[1], 9) == 0 && ac < 6))
		return (0);
	if (ac < 5)
		return (0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	if (!envp[0])
		return (0);
	if (!check_nb_args(ac, av))
		return (0);
	
}