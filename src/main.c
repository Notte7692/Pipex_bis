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

//Fonction to stock av in a tab
char **stock_av(int ac, char **av)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (i <= ac - 1)
	{
		if (open(av[i], O_RDONLY) > 0)
			count++;
		i++;
	}
	i = 1;
	while
}

//Main function of the progrann
int	main(int ac, char **av)
{
	t_struct	pipex;
	char		**tab_av;
	int			i;

//stocker les av

	i = 1;
	if (ac != 5)
		ft_printf("Wrong number of argument");
//recuperer le fd
	tab_av = malloc(sizeof(char *) * (ac -1) + 1);
	if (!tab_av)
		return (NULL);
	while (i < (ac -1))
	{

	}
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_printf("ERROR WITH THE FILE");
}
