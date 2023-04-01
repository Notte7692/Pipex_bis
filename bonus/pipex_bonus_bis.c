#include "../includes/pipex_bonus_bis.h"

char **parse_command(int ac, char **av)
{
    char    **command;
    
    if (ac < 5)
        return (NULL);

    return &av[2];
}

void swap_pipe(int *pipe1, int *pipe2)
{
	int fd0 = pipe1[0];
	int fd1 = pipe1[1];

	pipe1[0] = pipe2[0];
	pipe1[1] = pipe2[1];
	pipe2[0] = fd0;
	pipe2[1] = fd1;
}

char	*find_path(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char **get_command_args(char *command)
{
	char **args = ft_split(command, ' ');
	return args;
}

static char	*get_cmd(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*command;
	
	if (access(cmd, 0) == 0)
		return (cmd);
	
	while (*cmd_path)
	{
		tmp = ft_strjoin(*cmd_path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		cmd_path++;
	}
	return (NULL);
}

void close_all_fds(t_pipex *command)
{
	close(command->out);
	close(command->in);
	close(command->fds[0]);
	close(command->fds[1]);
	close(command->fds[2]);
	close(command->fds[3]);
}

void copy_fds(t_pipex *command, int* current_pipe, int *previous_pipe)
{
		command->fds[0] = current_pipe[0];
		command->fds[1] = current_pipe[1];
		command->fds[2] = previous_pipe[0];
		command->fds[3] = previous_pipe[1];
}

int execute_command(t_pipex *command, int* current_pipe, int *previous_pipe)
{
    int pid;
	char *full_path_command;
	char **args;
	
	args = get_command_args(command->cmd);
    pid = fork();
    if (pid == 0)
    {
		full_path_command = get_cmd(command->paths, args[0]);
		if (full_path_command != NULL)
		{
			printf("(%d -> ", command->in);
			printf("[%s] ", command->cmd);
			printf("-> %d)\n", command->out);
			dup2(command->out, 1);
			dup2(command->in, 0);
			close_all_fds(command);
			execve(full_path_command, args, command->env);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
    }
	return (pid);
}

char **extract_path(char **envp)
{
    char *paths = find_path(envp);
    char **paths_splitted = ft_split(paths, ':');
    return paths_splitted;
}

void wait_for_pids(int *pids, int size)
{
	int i;

	i = size - 1;
	while (i >= 0)
	{
		waitpid(pids[i], NULL, 0);
		printf("successfully executed %d\n", pids[i]);
		i--;
	}
}

int main(int ac, char **av, char **envp)
{
    char        **commands;
    t_pipex     cmd;
    int         i;
    int         current_pipe[2];
	int			previous_pipe[2];
	char		**paths;
	int			*pids;

    commands = parse_command(ac, av);
    if (commands == NULL)
	{
        return (EXIT_FAILURE);
    }

	pids = malloc(sizeof(int) * ac - 3);
	paths = extract_path(envp);
    i = 0;

    while (i < ac - 3)
    {
        cmd.cmd = commands[i];
        if (i == 0)
        {
            cmd.in = open(av[1], O_RDONLY);
        }
        else
        {
            cmd.in = previous_pipe[0];
        }

        if (i == ac - 4)
        {
            cmd.out = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
        }
        else
		{
 	       	pipe(current_pipe);
            cmd.out = current_pipe[1];
			swap_pipe(&previous_pipe, &current_pipe);
        }
        cmd.env = envp;
		cmd.paths = paths;
		copy_fds(&cmd, current_pipe, previous_pipe);
       	pids[i] = execute_command(&cmd, current_pipe, previous_pipe);
		close(cmd.in);
		close(cmd.out);
		i++;
    }
	close_all_fds(&cmd);
	wait_for_pids(pids, ac - 3);
	free(pids);
	return 0;
}
