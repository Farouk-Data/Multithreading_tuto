#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

//roll a dice and return the result of the dice 

pthread_mutex_t mutex;

void	*roll_dice(void)
{
	int value;
	int	*result;


	result = malloc(sizeof(int));
	value = (rand() % 6) + 1;
	pthread_mutex_lock(&mutex);
	*result = value;
	pthread_mutex_unlock(&mutex);
	//checking the address
	//printf("Address = %p\n", result);
	return ((void *)result);
}

int main(void)
{
	int	i;
	int	*res;
	srand(time(NULL));
	pthread_t th[5];

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 5)
	{
		if (pthread_create(&th[i], NULL, (void *)&roll_dice, NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(th[i], (void **)&res))
			return (2);
		i++;
	}
	//checking the address
	pthread_mutex_destroy(&mutex);
	// printf("Dice = %d\nAddress = %p\n", *res, res);
	printf("Dice = %d\n", *res);
	free(res);
	return (0);
}