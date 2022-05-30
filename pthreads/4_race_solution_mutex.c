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
	pthread_t t1, t2, t3;

	//initialize mutex
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, (void *)&routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, (void *)&routine, NULL) != 0)
		return (2);
	if (pthread_create(&t3, NULL, (void *)&routine, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (3);
	if (pthread_join(t2, NULL) != 0)
		return (3);
	if (pthread_join(t3, NULL) != 0)
		return (4);
	//when you re done , destroy the mutex
	pthread_mutex_destroy(&mutex);
	printf("Mails = %d\n", mails);
	return (0); 
}