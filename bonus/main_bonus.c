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

int	main(int ac, char **av, char **envp)
{
	t_struct	pipex;

	if (ac < min_arg(av[1], &pipex))
	{
		ft_prntf("wrong number of arguments");
		return (0);
	}
}