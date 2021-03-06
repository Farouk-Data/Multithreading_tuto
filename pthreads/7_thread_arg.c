#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//create 10 thrds, each taking a unique prime from the primes array and print it on the screen
int	g_primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("thread[%d] = %d\n", index, g_primes[index]);
	free(arg);
	return (NULL);
}

int	main(void)
{
	int			i;
	int			*ptr;
	pthread_t	th[10];

	i = 0;
	while (i < 10)
	{
		ptr = (int *)malloc(sizeof(int));
		*ptr = i;
		if (pthread_create(&th[i], NULL, (void *)&routine, ptr))
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL))
			return (2);
		i++;
	}
	return (0);
}