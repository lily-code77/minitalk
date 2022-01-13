#include "minitalk.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return;
}

void ft_putnbr_fd(int n, int fd)
{
    char c;
    
    if (n == -2147483648)
    {
        ft_putnbr_fd(n / 10, fd);
        n = (-1) * (n % 10);
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = (-1) * n;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
    {
        c = n + '0';
        ft_putchar_fd(c, fd);
    }
    return;
}
