#include "../includes/pipex_bonus_bis.h"
#include <errno.h>

void	close_fd(int *fd)
{
	if (*fd < 0)
		return ;
	close(*fd);
	*fd = -1;
}


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

char **parse_command(char **av, int doc)
{
	if (doc)
		return(&av[3]);
    return &av[2];
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
		if (command != NULL && access(command, 0) == 0)
		{
			free(tmp);
			return (command);
		}
		free(tmp);
		free(command);
		cmd_path++;
	}
	return (ft_strjoin("", cmd));
}

char **extract_path(char **envp)
{
    char *paths = find_path(envp);
    char **paths_splitted = ft_split(paths, ':');
    return paths_splitted;
}

int execute_command(t_pipex *command, int i)
{
    int pid;
	char *full_path_command;
	char **args;

	
	args = get_command_args(command->cmd);
    pid = fork();
    if (pid == 0)
    {
		command->paths = extract_path(command->env);
		if (i == 0)
		{
			if (command->heredoc == 0)
				command->in = open(command->infile, O_RDONLY);
			close_fd(&command->fds[0]);
			dup2(command->in, STDIN_FILENO);
			close_fd(&command->in);
			dup2(command->fds[1], STDOUT_FILENO);
			close_fd(&command->fds[1]);
		}
		else if (i == command-> ac - 1)
		{
			command->out = open(command->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(command->previous_pipes, STDIN_FILENO);
			close_fd(&command->previous_pipes);
			dup2(command->out, STDOUT_FILENO);
			close_fd(&command->out);
		}
		else
		{
			close_fd(&command->fds[0]);
			dup2(command->previous_pipes, STDIN_FILENO);
			close_fd(&command->previous_pipes);
			dup2(command->fds[1], STDOUT_FILENO);
			close_fd(&command->fds[1]);
		}
		full_path_command = get_cmd(command->paths, args[0]);
		if (full_path_command == NULL)
		{
			write(2,"Command not found :\n", 20);
			free_tab(command->paths);
			free_tab(args);
			free(command->pids);
			exit (EXIT_FAILURE);
		}
		free_tab(command->paths);
		execve(full_path_command, args, command->env);
		if (full_path_command[0] != '/')
		{
			free(full_path_command);
		}
			free_tab(args);
			free(command->pids);
		exit(EXIT_FAILURE);
    }
	// close(command->previous_pipes);
	free_tab(args);
	return (pid);
}



void wait_for_pids(int *pids, int size)
{
	int i;

	i = -1;
	while (++i < size)
		waitpid(pids[i], NULL, 0);
}

void	here_doc(char *av, t_pipex *cmd)
{
	char	*buf;

	pipe(cmd->fds);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0, 0);
		if (!buf || ft_strncmp(buf, av, ft_strlen(av)) == 0)
			break ;
		write(cmd->fds[1], buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	get_next_line(0, 1);
	close(cmd->fds[1]);
	cmd->in = cmd->fds[0];
}



int	check_args(char **av, char **envp, int ac)
{
	char	**paths;
	int		i;
	char	*cmd;
	char	**args;

	paths = extract_path(envp);
	i = 2;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		i = 3;
	
	while (i < ac -1)
	{
		args = get_command_args(av[i]);
		cmd = get_cmd(paths, args[0]);
		if (cmd == 0)
		{
			free(cmd);
			free_tab(paths);
			free_tab(args);
			return (0);
		}
		free_tab(args);
		free(cmd);
		i++;
	}
	free_tab(paths);
	return (1);
}

void	init(t_pipex *cmd, char **av, int ac)
{
	ft_memset(cmd, 0, sizeof(t_pipex));
	if (ft_strcmp("here_doc", av[1]) == 0)
	{
		if (ac < 6)
			exit (0);
		here_doc(av[2], cmd);
		cmd->heredoc = 1;
	}
	cmd->previous_pipes = -1;
	cmd->ac = ac - (3 + cmd->heredoc);
	cmd->infile = av[1];
	cmd->outfile = av[ac - 1];
	cmd->pids = ft_calloc(ac - (3 + cmd->heredoc == 1), sizeof(int));
	if (cmd->pids == NULL)
		exit(1);
}


int main(int ac, char **av, char **envp)
{
    char        **commands;
    t_pipex     cmd;
    int         i;
	int			len;

	i = 0;
	if (ac >= 5)
	{
		init(&cmd, av, ac);
		commands = parse_command(av, cmd.heredoc);
		if (envp[0])
		{
			cmd.env = envp;
			//cmd.paths = extract_path(envp);
		}
		len = ac - (3 + cmd.heredoc); 
		while (i < len)
		{
			cmd.cmd = commands[i];
			if (i != ac - 4)
				pipe(cmd.fds);
			cmd.pids[i] = execute_command(&cmd, i);
			close_fd(&cmd.fds[1]);
			if (cmd.previous_pipes != -1)
				close_fd(&cmd.previous_pipes);
			if (cmd.heredoc)
			{
				close_fd(&cmd.in);
				close_fd(&cmd.out);
				cmd.heredoc = 0;
			}
			cmd.previous_pipes = cmd.fds[0];
			i++;
		}
		wait_for_pids(cmd.pids, ac - (3 + (cmd.heredoc == 1)));
		free(cmd.pids);
	}
	return (0);
}
