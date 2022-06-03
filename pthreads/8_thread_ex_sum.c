#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//create 10 thrds, each taking a unique prime from the primes array and print it on the screen
int	g_primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	i;
	int	index;
	int	sum;

	i = 0;
	sum = 0;
	index = *(int *)arg;
	while (i < 5)
	{
		sum += g_primes[index + i];
		i++;
	}
	printf("Local sum : %d\n", sum);
	*(int *)arg = sum;
	return (arg);
}

int	main(void)
{
	int			i;
	int			*res;
	int			g_sum;
	int			*ptr;
	pthread_t	th[2];

	i = 0;
	g_sum = 0;
	while (i < 2)
	{
		ptr = (int *)malloc(sizeof(int));
		*ptr = i * 5;
		if (pthread_create(&th[i], NULL, (void *)&routine, ptr))
			return (1);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (pthread_join(th[i], (void **)&res))
			return (2);
		g_sum += *res;
		free(res);
		i++;
	}
	printf("Global sum is: %d\n", g_sum);
	return(0);
}