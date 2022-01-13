#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

static int  space(const char str)
{
    if (str == ' ' || str == '\f' || str == '\n'
        || str == '\r' || str == '\t' || str == '\v')
        return (1);
    return (0);
}

static int  is_over(long n, int m)
{
    return (n > (LONG_MAX - m) / 10);
}

static int  which_sign(int sign)
{
    if (sign == -1)
        return((int)LONG_MIN);
    if (sign == 1)
        return((int)LONG_MAX);
    return (0);
}

int ft_atoi(const char *str)
{
    long result;
    int sign;
    size_t  i;

    sign = 1;
    result = 0;
    i = 0;
    while (space(str[i]))
        i ++;
    if (str[i] == '-' || str[i] == '+')
        sign = (str[i ++] - 44) * -1;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        if (is_over(result, (str[i] - '0')))
            return (which_sign(sign));
        result = result * 10 + (str[i] - '0');
        i ++;
    }
    return ((int)result * sign);
}
