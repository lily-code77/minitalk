#include "minitalk.h"

static void	sig_handler(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (signum == SIGUSR1)//SIGUSR1 represents 0
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)//SIUSR2 represents 1
		c |= 0x80 >> bits;
	bits ++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
