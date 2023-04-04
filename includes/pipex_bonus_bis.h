#ifndef PIPEX_BONUS_BIS_H
# define PIPEX_BONUS_BIS_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct  s_pipex
{
    int     in;
    int     out;
    char    *cmd;
    char    **env;
    char    **paths;
    int     fds[4];
    int		pids;
} t_pipex;

typedef struct  s_fork
{
    pid_t   pid;
    int     in;
    int     out;
} t_fork;


#endif


	// #./bonus/child_bonus.c \
	// #./bonus/error_bonus.c \
	// #./bonus/free_bonus.c \
	// #./bonus/get_file_bonus.c \
	// #./bonus/heredoc_bonus.c \
	// #./bonus/main_bonus.c \#
