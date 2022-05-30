#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int x = 2;
	int pid = fork();
	if (pid == -1)
		return 1;
	//if we are in the child process
	if (pid == 0)
		x++;
	sleep(2);
	printf("X = %d\n",x);
	//printf("Process iD: %d\n",getpid());
	if (pid != 0)
		wait(NULL);
	return 0;
}