#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* int	main(void)
{
	printf("hello world from process ID %d\n", getpid());
	exit(0);
} */

int	main()
{
	int	a, b;
	a = fork();
	printf("a = %d\n", a);
	printf("Before\n");
	b = fork();
	printf("b = %d\n", b);
	printf("After\n");
	printf("===\n");
	return(0);
}

