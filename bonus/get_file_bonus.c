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
	if (!ft_strncmp("here_doc", av[1], 9))
		here_doc(av[2], pipex);
	else
	{
		pipex->infile = open(av[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_error("Infile");
	}
}

void	get_outfile(char *av, t_struct *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		msg_error("Outfile");
}
