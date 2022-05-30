#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int main(void)
{
	long int	a;

	a = 0;
	for (long int i = 1; i <= 1000000; i++)
	{
		a = a + i;
	}
	printf("%ld\n", a);
}