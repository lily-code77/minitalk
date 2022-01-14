#include "minitalk.h"

static void	send_char(pid_t pid, char c)
{
	int	bit;
	int	j;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			j = kill(pid, SIGUSR2);
			if (j == -1)
				exit (1);
		}
		else
		{
			j = kill(pid, SIGUSR1);
			if (j == -1)
				exit (1);
		}
		usleep(100);
		if (bit == 0)
			break;
		bit --;
	}
}

static void send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i ++;
	}
	send_char(pid, '\0');
}

static void success(int sig)//
{
	(void)sig;
	write(1, "Received PID", 13);
}

static int	input_digits(char *input)//
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if ((input[i] >= '0' && input[i] <= '9') == 0)
			return (0);
		i ++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3 || input_digits(argv[1]) == 0)//
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!signal(SIGUSR1, success))
	{
		write(2, "Wrong PID", 10);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_str(pid, str);
	return (0);
}
