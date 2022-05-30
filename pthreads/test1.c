#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void	*routine(void)
{
	//pthread_mutex_lock(&lock);
	write(1, "thread1\n",8);
	//pthread_mutex_unlock(&lock);
	return (0);
}

void	*routine2(void)
{
	//pthread_mutex_lock(&lock);
	write(1, "thread2\n",8);
	//pthread_mutex_unlock(&lock);
	return (0);
}

int main(void)
{
	//var to store info about threads (structure)
	pthread_t thread1, thread2 ;
	
	//initialize a mutex
	//pthread_mutex_init(&lock, NULL);

	//initialize a thread
	pthread_create(&thread1, NULL, (void *)&routine, NULL);
	pthread_create(&thread2, NULL, (void *)&routine2, NULL);


	//wait for the thread to finish the execution(its like wait function for threads)
	pthread_join(thread1, NULL); //second arg for a pointer if the thread was returning something
	pthread_join(thread2, NULL);

	return (0);
}