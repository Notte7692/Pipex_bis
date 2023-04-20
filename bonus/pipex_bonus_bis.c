#include "../includes/pipex_bonus_bis.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char **parse_command(int ac, char **av)
{
	if (av[1] && !ft_strncmp("here_doc", av[1], 9))
		return (&av[2]);
    else if (ac < 5)
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

	if (cmd != NULL && access(cmd, 0) == 0)
		return (cmd);
	
	while (*cmd_path)
	{
		tmp = ft_strjoin(*cmd_path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (command != NULL && access(command, 0) == 0)
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

void copy_fds(t_pipex *command, int *current_pipe, int *previous_pipe)
{
		command->fds[0] = current_pipe[0];
		command->fds[1] = current_pipe[1];
		command->fds[2] = previous_pipe[0];
		command->fds[3] = previous_pipe[1];
}

int execute_command(t_pipex *command, int i)
{
    int pid;
	char *full_path_command;
	char **args;
	
	args = get_command_args(command->cmd);
    pid = fork();
    if (pid == 0 && args[0] != NULL)
    {
		full_path_command = get_cmd(command->paths, args[0]);
		if (full_path_command != NULL)
		{
			printf("(%d -> ", command->in);
			printf("[%s] ", command->cmd);
			printf("-> %d)\n", command->out);
			dup2(command->out, 1);
			dup2(command->in, 0);
			if (i == 0)
			{
				close(command->out);
				close(command->in);
				close(command->fds[2]);
				close(command->fds[3]);
			}
			else
				close_all_fds(command);
			execve(full_path_command, args, command->env);
		}
		else
		{
			free_tab(args);
			free(full_path_command);
			exit(EXIT_FAILURE);
		}
    }
	free_tab(args);
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

void	here_doc(char *av, t_pipex *cmd)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		ft_printf("ERR_HEREDOC");
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!ft_strncmp(av, buf, ft_strlen(av) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	close(file);
	cmd->in = open(".heredoc_tmp", O_RDONLY);
	if (cmd->in < 0)
	{
		unlink(".heredoc_tmp");
		ft_printf("ERR_HEREDOC");
	}
}

int main(int ac, char **av, char **envp)
{
    char        **commands;
    t_pipex     cmd;
    int         i;
	int			fd;
    int         current_pipe[2];
	int			previous_pipe[2];
	int			*pids;
	
	fd = open(av[1], O_RDONLY);
	if (ft_strncmp("here_doc", av[1], 9) != 0 && fd < 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
    commands = parse_command(ac, av);
    if (commands == NULL)
	{
        return (EXIT_FAILURE);
    }

	pids = malloc(sizeof(int) * ac - 3);
    i = 0;
    while (i < ac - 3)
    {
        cmd.cmd = commands[i];
        if (i == 0)
        {
			if (ft_strncmp("here_doc", av[1], 9) == 0)
				here_doc(av[2], &cmd);
			else
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
			swap_pipe(previous_pipe, current_pipe);
        }
		if (cmd.cmd != NULL)
		{
        	cmd.env = envp;
			cmd.paths = extract_path(envp);
			copy_fds(&cmd, current_pipe, previous_pipe);
       		pids[i] = execute_command(&cmd, i);
		}
		close(cmd.in);
		close(cmd.out);
		free_tab(cmd.paths);
		i++;
    }
	close_all_fds(&cmd);
	wait_for_pids(pids, ac - 3);
	free(pids);
	return 0;
}
