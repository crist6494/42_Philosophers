#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


pthread_mutex_t	count_mutex;
static int count = 10;

void	*thread1_routine(void * unused)
{
	int i = 0;

	while(i < 10000)
	{
		pthread_mutex_lock(&count_mutex);
		count++;
		pthread_mutex_unlock(&count_mutex);
		i++;
	}
	return (0);
}

void	*thread2_routine(void * unused)
{
	int i = 0;

	while(i < 10000)
	{
		pthread_mutex_lock(&count_mutex);
		count--;
		pthread_mutex_unlock(&count_mutex);
		i++;
	}
	return (0);
}

void errorExit(char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char **argv)
{
	pthread_t	thread1;
	pthread_t	thread2;
	
	pthread_mutex_init(&count_mutex, NULL);

	if(pthread_create(&thread1, NULL, thread1_routine, NULL) != 0)
		errorExit("thread1 cannot be created");

	if(pthread_create(&thread2, NULL, thread2_routine, NULL) != 0)
		errorExit("thread2 cannot be created");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("count value %d \n", count);
	pthread_mutex_destroy(&count_mutex);
	return (0);
}