#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


//if we test the pid , we will find the same PID 
//we can have multiple threads inside a process but not vice versa
int x = 2;

void	*routine(void)
{
	//printf("testing threads.\n");
	x++;
	sleep(2);
	printf("Value of x: %d\n", x);
	return(NULL);
}

void	*routine2(void)
{
	sleep(2);
	printf("Value of x: %d\n", x);
	return (NULL);
}

int main(void)
{
	pthread_t thread1, thread2;

	if (pthread_create(&thread1, NULL, (void*)&routine, NULL))
		return 1;
	if (pthread_create(&thread2, NULL, (void*)&routine2, NULL))
		return 1;
	if (pthread_join(thread1, NULL))
		return 2;
	if (pthread_join(thread2, NULL))
		return 2;
	return 0;
}