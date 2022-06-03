#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_NUM 2

void	*routine(void *args)
{

}

int main()
{
	pthread_t	th[THREAD_NUM];
	int			i;

	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_create(&th[i], NULL, (void *)&routine, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL))
			return (2);
		i++;
	}
	return (0);
}