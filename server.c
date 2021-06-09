#include "minitalk.h"

int	g_cnt;
int	g_symb;

static void	sig_zero(int sig)
{
	g_cnt /= 2;
	(void)sig;
}

static void	sig_one(int sig)
{
	g_symb += g_cnt;
	g_cnt /= 2;
	(void)sig;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	g_cnt = 128;
	signal(SIGUSR1, &sig_one);
	signal(SIGUSR2, &sig_zero);
	while (1)
	{
		if (g_cnt == 0)
		{
			write(STDOUT_FILENO, &g_symb, 1);
			g_cnt = 128;
			g_symb = 0;
		}
		pause();
	}
	return (0);
}
