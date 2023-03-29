/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:53 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/29 16:10:20 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipe(t_struct *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->outfile);
	close(pipex->infile);
}

//Main function of the progrann
int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (envp == NULL || *envp == NULL)
		return (0);
	if (ac != 5)
		return(mess_err("Wrong numbers of args"));
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		error("Infile");
	pipex.outfile = open(av[ac -1], O_TRUNC | O_CREAT | O_RDWR, 000644);
	if (pipex.outfile < 0)
		error("Outfile");
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	if (pipe(pipex.pipefd) < 0)
		error("Error pipe");
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, av, envp);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return (0);
}
