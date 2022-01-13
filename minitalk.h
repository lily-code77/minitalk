#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

#endif
