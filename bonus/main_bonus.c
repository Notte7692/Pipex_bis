/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:48:00 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/29 17:13:39 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	min_arg(char *av, t_struct *pipex)
{
	if (av && !ft_strncmp("here_doc", av, 9))
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
		return(msg("invalid number of args"));
	get_infile(av, &pipex);
	get_outfile(av[ac - 1], &pipex);
	pipex.nb_cmd = ac - 3 - pipex.here_doc;
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.nb_pipe);
	if (!pipex.pipe)
		msg_error("pipe");
	pipex.env_path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.env_path, ':');
	if (!pipex.cmd_path)
		free_pipe(&pipex);
	create_pipes(&pipex);
	pipex.index = -1;
	while (++(pipex.index) < pipex.nb_cmd)
		child(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	free_parent(&pipex);
	return (0);
	while (i < pipex->nbcmds)
	{
		if (pipe(pipex->fd) < 0)
			return (0);
		pid[i] == fork();
		if (pid[i] < 0)
			return ;
		if (pid[i] == 0)
		{
			if (i == 0)
			{
				dup2(infile, 0);
				close(infile);
			}
			if (i != 0)
			{
				dup2(pipex->prev_pipes, 0);
				close(prev_pipes);
			}
			if (i != pipex->nbcmds - 1)
			{
				dup2(pipex->fd[1], 1);
				close(fd[1]);
			}
			if (i == pipex->nbcmds - 1)
			{
				dup2(outfile, 1);
				close(outfile);
			}
			close(pipex->fd[0]);
			close(fd[1]);
		}
		else
		{
			if (pipex->prev_pipes != -1)
				close(pipex->prev_pipes);
			pipex->prev_pipes = pipex->pipe[0];
		}
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (ac < min_arg(av[1], &pipex));
		return (msg("wrong number of args"));
	get_infile(av, &pipex);
	get_outfile(av[ac -1], &pipex);
	pipex.nb_cmd = ac - 3;
	if(pipe(pipex.pipe) < 0)
		msg_error("error pipe");
	
}