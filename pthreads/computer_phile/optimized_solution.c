#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//program that adds up all the numbers from 1 to 1 million but 
// doing it two thread

//volatile : letting the compiler know that the variable is going to change
//while ruuning
volatile long int a = 0;
pthread_mutex_t aLock;

//working with mutexes
//cons: locking the thread slow the program down 
void	thread_func1(void *arg)
{
	int			i;
	long int	localA = 0;

	for (i = 1; i < 500000; i++)
	{  
		localA = localA + i;
	}
	pthread_mutex_lock(&aLock);
	a = a + localA;
	pthread_mutex_unlock(&aLock);
}

void	thread_func2(void *arg)
{
	int			i;
	long int	localA = 0;

	for (i = 500000; i <= 1000000; i++)
	{
		localA = localA + i;
	}
	pthread_mutex_lock(&aLock);
	a = a + localA;
	pthread_mutex_unlock(&aLock);
}

int main(void)
{
	pthread_t one, two;

	int i;
	a = 0;

	pthread_mutex_init(&aLock, NULL);
	pthread_create(&one, NULL, (void *)&thread_func1, NULL);
	pthread_create(&two, NULL, (void*)&thread_func2, NULL);

	pthread_join(one, NULL);
	pthread_join(two, NULL);

	printf("%ld\n",a);
}