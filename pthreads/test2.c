#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define Error_thread 5

void	*routine(void)
{
	write(1, "thread1\n",8);
	sleep(2);
	write(1, "End\n",4);
	return (0);
}

int main(void)
{

	//var to store info about threads (structure)
	pthread_t thread1, thread2 ;

	//initialize a thread - Error Checking the return of function calls
	if (pthread_create(&thread1, NULL, (void *)&routine, NULL) != 0)
		return (Error_thread);
	if (pthread_create(&thread2, NULL, (void *)&routine, NULL) != 0)
		return (Error_thread);
		 
	//wait for the thread to finish the execution(its like wait function for threads)
	if (pthread_join(thread1, NULL)) //second arg for a pointer if the thread was returning something
		return (Error_thread);
	if (pthread_join(thread2, NULL))
		return (Error_thread);
}

//the proof that they are running in parallel is that the first
// write() is executed simultaneously the same for the seconf

/* Output:
	>> thread1
	>> thread1
	...waiting 3 seconds...
	>> End
	>> End
*/