/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <nsalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:25:32 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/04/06 21:00:19 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	mess_err(char *err)
{
	write(2, err, ft_strlen_mod(err));
	write(1, "\n", 1);
	return (1);
}

void	error_b(char *err)
{
	perror(err);
	exit (1);
}
