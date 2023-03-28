#include "../includes/pipex_bonus.h"

void	here_doc(char *av, t_struct *pipex)
{
	int		fd;
	char	*line;

	fd = open(".here_doc_tmp", O_CREAT | O_TRUNC | O_WRONLY, 0644),
	if (fd < 0)
		msg_error("here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0) < 0, &line)
			exit(1);
		if (!ft_strncmp(av, line, ft_strjoin_mod(av) + 1))
			break ;
		write(fd, line, ft_strlen_mod(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
	close(fd);
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink(".heredoc_tmp");
		msg_error("here_doc");
	}
}