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

//Main function of the progrann
int	main(int ac, char **av)
{
	t_struct	pipex;

	if (ac != 5)
		ft_printf("Wrong number of argument");
//recuperer le fd
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_printf("ERROR WITH THE FILE");
}
