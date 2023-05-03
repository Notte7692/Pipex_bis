/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:53 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/05/03 13:53:59 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(char *av, t_pipex *cmd)
{
	char	*buf;

	pipe(cmd->fds);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0, 0);
		if (!buf || ft_strncmp(buf, av, ft_strlen(av)) == 0)
			break ;
		write(cmd->fds[1], buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	get_next_line(0, 1);
	close(cmd->fds[1]);
	cmd->in = cmd->fds[0];
}
