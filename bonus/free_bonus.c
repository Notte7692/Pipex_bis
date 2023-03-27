#include "../includes/pipex_bonus.h"

void    free_pipe(t_struct *pipex)
{
    close(pipex->infile);
    close(pipex->outfile);
    if (pipex->here_doc)
        unlink("heredoc.tmp");
    free(pipex->pipe);
    msg_error("error ENVP");
    exit(1);
}

void    free_parent(t_struct *pipex)
{
    int i;

    i = 0;
    close(pipex->infile);
    close(pipex->outfile);
    if (pipex->here_doc)
        unlink("heredoc.tmp");
    while (pipex->cmd_path[i])
    {
        free(pipex->cmd_path[i]);
        i++;
    }
    free(pipex->cmd_path);
    free(pipex->pipe);
}

void    free_child(t_struct *pipex)
{
    int i;

    i = 0;
    while (pipex->cmd_arg[i])
    {
        free(pipex->cmd_arg[i]);
        i++;
    }
    free(pipex->cmd_arg);
    free(pipex->cmd);
}