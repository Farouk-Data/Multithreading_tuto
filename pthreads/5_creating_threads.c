#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int	mails = 0;
pthread_mutex_t mutex;


/*the lock in the mutex basically preserve other threads from accessing 
the memory of the variable and changing its value 
before the thread in action finishes its execution*/
void	*routine(void)
{ 
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	//storing threads in an array (array of threads)
	pthread_t th[8];
	int	i;

	i = 0;
	//initialize mutex
	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&th[i], NULL, (void *)&routine, NULL) != 0)
			return (1);
		printf("Thread %d has started.\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (3);
		printf("Thread %d has died.\n", i);
		i++;
	}
	//when you re done , destroy the mutex
	pthread_mutex_destroy(&mutex);
	printf("Mails = %d\n", mails);
	return (0); 
}