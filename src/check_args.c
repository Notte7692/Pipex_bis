/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:15:00 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/04 10:41:18 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_path(char *cmd, char **paths, char **args)
{
	free(cmd);
	free_tab(paths);
	free_tab(args);
}

char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;

	if (cmd != NULL && access(cmd, 0) == 0)
		return (ft_strjoin("", cmd));
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
