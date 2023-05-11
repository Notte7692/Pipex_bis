/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:08:15 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/11 16:30:09 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	get_path(char *cmd, char **paths, char **args)
{
	free(cmd);
	free_tab(paths);
	free_tab(args);
}

int	verif_cmd(char *cmd)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(cmd))
	{
		if (cmd[i] == '/' && cmd[i + 1] == '/')
			return (0);
		i++;
	}
	return (1);
}

char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;

	if (cmd != NULL && ft_strchr(cmd, '/') && access(cmd, 0) == 0)
		return (ft_strjoin("", cmd));
	if (cmd_path != NULL && cmd_path[0] != NULL)
	{
		while (*cmd_path && cmd_path != NULL)
		{
			tmp = ft_strjoin(*cmd_path, "/");
			command = ft_strjoin(tmp, cmd);
			if (command != NULL && access(command, 0) == 0
				&& verif_cmd(command))
			{
				free(tmp);
				return (command);
			}
			free(tmp);
			free(command);
			cmd_path++;
		}
	}
	command_not_found(cmd);
	return (NULL);
}

int	check_args(char **av, char **envp, int ac)
{
	char	**paths;
	int		i;
	char	*cmd;
	char	**args;

	paths = extract_path(envp);
	i = 2;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		i = 3;
	while (i < ac -1)
	{
		args = get_command_args(av[i]);
		cmd = get_cmd(paths, args[0]);
		if (cmd == 0)
		{
			get_path(cmd, paths, args);
			return (0);
		}
		free_tab(args);
		free(cmd);
		i++;
	}
	free_tab(paths);
	return (1);
}
