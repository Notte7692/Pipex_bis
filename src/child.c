/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:06:07 by nsalhi            #+#    #+#             */
/*   Updated: 2023/03/17 16:36:20 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;
	
	while(*cmd_path)
	{
		tmp = ft_strjoin(*cmd_path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_path++;
	}
	return (NULL);
}



void    first_child(t_struct pipex, char **av, char **envp)
{
	dup2(pipex.pipefd[1], 1);
	close(pipex.pipefd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_arg = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_arg[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		mess_err("Error command not found");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}

void	second_child(t_struct pipex, char **av, char **envp)
{
	dup2(pipex.pipefd[0],0);
	close(pipex.pipefd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_arg = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_arg[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		mess_err("Error command not found");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}