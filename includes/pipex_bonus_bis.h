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
    int     ac;
    int     dc_file;
    int     previous_pipes;
    int     heredoc;
    int     out;
    char    *cmd;
    char    **env;
    char    **paths;
    int     *pids;
    char    *infile;
    char    *outfile;
    int     fds[2];
 
} t_pipex;

typedef struct  s_fork
{
    pid_t   pid;
    int     in;
    int     out;
} t_fork;


#endif