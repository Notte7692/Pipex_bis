#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

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

/* child.c*/
int     execute_command(t_pipex *command, int i);
void	child(t_pipex *command, int i, char **args);

/*error_child_bonus.c*/
void    error_full_path(t_pipex *command, char **args);

/*pipex_bonus.c*/
char 	**extract_path(char **envp);
char 	**get_command_args(char *command);

/* pipex_bonus_utils.c*/
int		close_fd(int *fd);
void	free_tab(char **tab);
char    **parse_command(char **av, int doc);
char	*find_path(char **envp);
char    **get_command_args(char *command);

/*here_doc_bonus.c*/
void	here_doc(char *av, t_pipex *cmd);

/*free_bonus.c*/
void	ft_free_child(t_pipex *command, char **args);

/*check_args_bonus.c*/
void	get_path(char *cmd, char **paths, char **args);
int	    check_args(char **av, char **envp, int ac);
char	*get_cmd(char **cmd_path, char *cmd);

#endif