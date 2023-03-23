/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:07:00 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/23 19:11:10 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	get_infile(char **av, t_struct *pipex)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		ft_printf("Error infile");
	}
}
