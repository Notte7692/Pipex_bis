/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:02:58 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/03 15:48:53 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	**extract_path(char **envp)
{
	char	*paths;
	char	**paths_splitted;

	paths = find_path(envp);
	paths_splitted = ft_split(paths, ':');
	return (paths_splitted);
}

void	wait_for_pids(int *pids, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(pids[i], NULL, 0);
}

void	init(t_pipex *cmd, char **av, int ac)
{
	ft_memset(cmd, 0, sizeof(t_pipex));
	if (ft_strcmp("here_doc", av[1]) == 0)
	{
		if (ac < 6)
			exit (0);
		here_doc(av[2], cmd);
		cmd->heredoc = 1;
	}
	cmd->previous_pipes = -1;
	cmd->ac = ac - (3 + cmd->heredoc);
	cmd->infile = av[1];
	cmd->outfile = av[ac - 1];
	cmd->pids = ft_calloc(ac - (3 + cmd->heredoc == 1), sizeof(int));
	if (cmd->pids == NULL)
		exit(1);
}

void	core(t_pipex *cmd, int ac, int i, char **commands)
{
	cmd->cmd = commands[i];
	if (i != ac - 4)
		pipe(cmd->fds);
	cmd->pids[i] = execute_command(cmd, i);
	close_fd(&cmd->fds[1]);
	if (cmd->previous_pipes != -1)
		close_fd(&cmd->previous_pipes);
	if (cmd->heredoc)
	{
		close_fd(&cmd->in);
		close_fd(&cmd->out);
		cmd->heredoc = 0;
	}
	cmd->previous_pipes = cmd->fds[0];
}

int	main(int ac, char **av, char **envp)
{
	char	**commands;
	t_pipex	cmd;
	int		i;
	int		len;

	i = 0;
	if (ac >= 5)
	{
		init(&cmd, av, ac);
		commands = parse_command(av, cmd.heredoc);
		if (envp[0])
			cmd.env = envp;
		len = ac - (3 + cmd.heredoc);
		while (i < len)
		{
			core(&cmd, ac, i, commands);
			i++;
		}
		wait_for_pids(cmd.pids, ac - (3 + (cmd.heredoc == 1)));
		free(cmd.pids);
	}
	return (0);
}
