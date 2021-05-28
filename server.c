#include "minitalk.h"

void	sig_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	if (argc != 1)
		exit(1);
	(void)argv;
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sleep(10);
	signal(SIGUSR1, &sig_handler);
	return (0);
}