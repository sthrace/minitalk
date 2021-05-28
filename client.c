#include "minitalk.h"

void	ft_sender(int ppid, char *message)
{
	int	i;

	i = -1;
	while(message[++i])
	{
		printf("Msg[%d]: %c\n", i, message[i]);
		kill(ppid, message[i]);
	}
}

int	main(int argc, char **argv)
{
	int	ppid;
	char	*message;

	if (argc != 3)
		exit(1);
	ppid = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	ft_sender(ppid, message);
	free(message);
	return (0);
}