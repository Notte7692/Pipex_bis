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
	while(strnchr("PATH", *envp, 4))
		evnp++;
	return (*evnp + 5);
}

//Main function of the progrann
int	main(int ac, char **av, char **envp)
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
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_printf("ERROR WITH THE FILE");
	pipex.outfile = open(av[ac -1], O_TRUNC | O_CREAT | O_RDWR, 000644);
	if (pipex.outfile < 0)
		ft_printf("Error outfile");
	pipex.path = find_path(envp)
	
}
