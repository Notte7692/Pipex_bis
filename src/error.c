/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nassimsalhi <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:25:32 by nassimsalhi       #+#    #+#             */
/*   Updated: 2023/03/19 15:25:33 by nassimsalhi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pipex.h"

int mess_err(char *err)
{
    write(2, err, ft_strlen_mod(err));
    return (1);
}

void    error(char *err)
{
    perror(err);
    exit (1);
}
