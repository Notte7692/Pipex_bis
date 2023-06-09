/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:30:44 by nsalhi            #+#    #+#             */
/*   Updated: 2023/05/09 15:31:33 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *av, t_pipex *cmd)
{
	char	*buf;
	char	*limiteur;

	pipe(cmd->fds);
	limiteur = ft_strjoin(av, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0, 0);
		if (!buf || ft_strncmp(buf, limiteur, ft_strlen(limiteur)) == 0)
			break ;
		write(cmd->fds[1], buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	free(limiteur);
	get_next_line(0, 1);
	close_fd(&cmd->fds[1]);
	cmd->in = cmd->fds[0];
}
