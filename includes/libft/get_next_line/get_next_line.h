/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalhi <<marvin@42.fr>>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:11:27 by nsalhi            #+#    #+#             */
/*   Updated: 2022/11/29 14:13:44 by nsalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int	    *get_next_line(int fd, char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_mod(char *left_str, char *buff);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int	    error(char *str);
int	    find_nwl(char *str);

#endif
