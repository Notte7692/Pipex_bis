#include "../includes/pipex_bonus.h"

static void sub_dup2(int zero, int first)
{
    dup2(zero, 0);
    dup2(first, 1);
}

static char get_cmd(char **path, char *cmd)
{
    char    *tmp;
    char    *command;

    while(*path)
    {
        tmp = ft_strjoin(*path, "/");
        command = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(command, 0) == 0)
            return (command);
        free (command);
        path++;
    }
    return (NULL);
}

void    child(t_struct pipex, char **av, char **envp)
{
    pipex.pid = fork();
    if (!pipex.pid)
    {
        if (pipex.pid == 0)
            sub_dup2(pipex.infile, pipex.pipe[1]);
        else if (pipex.pid = pipex.nb_cmd - 1)
            sub_dup2(pipex.pipe[2 * pipex.index - 2], pipex.outfile);
        else
            sub_dup2(pipex.pipe[2 * pipex.index - 2], piex.pipe[2 * pipex.index + 1]);

        close_pipes(&pipex);
        pipex.cmd_arg = ft_split(av[2 + pipex.here_doc + pipex.index] ' ');
        pipex.cmd = get_cmd(pipex.path, pipex.cmd_arg[0]);
        if (!pipex.cmd)
        {
            msg_pipe(pipex.cmd_aarg[0]);
            free_child(&pipex);
            exit(1);
        }
        execve(pipex.cmd, pipex.cmd_arg; envp);
    }
}