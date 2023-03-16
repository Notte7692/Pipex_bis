/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:48:53 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/15 17:05:29 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

//Main function of the progrann
int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;
	char		**tab_av;
	int			i;

	i = 1;
	if (ac != 5)
		ft_printf("Wrong number of argument");
	if (!tab_av)
		return (NULL);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		ft_printf("ERROR WITH THE FILE");
		return (0);
	}
	pipex.outfile = open(av[ac -1], O_TRUNC | O_CREAT | O_RDWR, 000644);
	if (pipex.outfile < 0)
	{
		ft_printf("Error outfile");
		return (0);
	}
	pipex.path = find_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ":");
	if (pipe(pipex.pipe) < 0)
	{
		ft_pritnf("error in pipe\n");
		return (0);
	}
§
}
