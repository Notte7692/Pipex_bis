/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:48:00 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/23 16:48:33 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	min_arg(char *av, t_struct *pipex)
{
	if (av && !ft_strncmp{"here_doc", av, 9})
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

char	*find_path(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

static void	create_pipes(t_struct *pipex)
{
	int	i;
	
	i = 0;
	while (i < pipex->nb_cmd - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			free_parent(pipex);
		i++;
	}
}

void	close_pipes(t_struct *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nb_pipe)
	{
		close(pipex->pipe[i]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (ac < min_arg(av[1], &pipex))
	{
		ft_prntf("wrong number of arguments");
		return (0);
	}
	get_infile(av, &pipex);
	get_outfile(av[ac - 1], &pipex);
	pipex.nb_cmb = ac - 3 - pipex.here_doc;
	pipex.nb_pipe = 2 * (pipex.nb_cmb - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.nb_pipe);
	if (!pipex.pipe)
		msg_error("pipe");
	pipex.env_path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.env_path);
	if (!pipex.cmd_path)
		free_pipe(&pipex);
	create_pipes(&pipex);
	pipex.index = -1;
	while (++(pipex.index < pipex.nb_cmd))
		child(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
}