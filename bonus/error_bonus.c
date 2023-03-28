#include "../includes/pipex_bonus.c"

int	msg(char *error)
{
	write(2, error, ft_strlen_mod(error));
	return (1);
}

void	msg_pipe(char *arg)
{
	write(2, "command not foudn", ft_strlen_mod("commeand not found"));
	write(2, arg, ft_strlen_mod(arg));
	write(2, "\n", 1);
}

void	msg_error(char *error)
{
	perror(err);
	exit (1);
}