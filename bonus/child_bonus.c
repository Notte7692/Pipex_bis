/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:11:18 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/03 14:16:35 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_start(t_pipex *command, char	**args)
{
	if (command->heredoc == 0)
	{
		command->in = open(command->infile, O_RDONLY);
		if (command->in == -1)
		{
			close(command->in);
			ft_free_child(command, args);
		}
	}
	if (close_fd(&command->fds[0]) == -1)
		ft_free_child(command, args);
	if (dup2(command->in, STDIN_FILENO))
		ft_free_child(command, args);
	if (close_fd(&command->in) == -1)
		ft_free_child(command, args);
	if (dup2(command->fds[1], STDOUT_FILENO) == -1)
		ft_free_child(command, args);
	if (close_fd(&command->fds[1]) == -1)
		ft_free_child(command, args);
}

void	last_child(t_pipex *command, char **args)
{
	command->out = open(command->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (command->out == -1)
	{
		ft_free_child(command, args);
	}
	if (dup2(command->previous_pipes, STDIN_FILENO) == -1)
		ft_free_child(command, args);
	if (close_fd(&command->previous_pipes) == -1)
		ft_free_child(command, args);
	if (dup2(command->out, STDOUT_FILENO) == -1)
		ft_free_child(command, args);
	if (close_fd(&command->out) == -1)
		ft_free_child(command, args);
}

void	child_mid(t_pipex *command, char **args)
{
	if (close_fd(&command->fds[0]) == -1)
		ft_free_child(command, args);
	if (dup2(command->previous_pipes, STDIN_FILENO) == -1)
		ft_free_child(command, args);
	if (close_fd(&command->previous_pipes) == -1)
		ft_free_child(command, args);
	if (dup2(command->fds[1], STDOUT_FILENO) == -1)
		ft_free_child(command, args);
	if (close_fd(&command->fds[1]) == -1)
		ft_free_child(command, args);
}

void	child(t_pipex *command, int i, char **args)
{
	char	*full_path_command;

	command->paths = extract_path(command->env);
	if (i == 0)
		child_start(command, args);
	else if (i == command-> ac - 1)
		last_child(command, args);
	else
		child_mid(command, args);
	full_path_command = get_cmd(command->paths, args[0]);
	if (full_path_command == NULL)
		error_full_path(command, args);
	free_tab(command->paths);
	execve(full_path_command, args, command->env);
	if (full_path_command[0] != '/')
		free(full_path_command);
	free_tab(args);
	free(command->pids);
	exit(EXIT_FAILURE);
}

int	execute_command(t_pipex *command, int i)
{
	int		pid;
	char	**args;

	args = get_command_args(command->cmd);
	pid = fork();
	if (pid == 0)
	{
		child(command, i, args);
	}
	free_tab(args);
	return (pid);
}
