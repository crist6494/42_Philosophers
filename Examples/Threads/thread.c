#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


void *thread_routine(void *arg)
{
	int i = 0;
	int fd;
	int n_lines = *((int*)arg);
	char buf[] = "Nueva line \n";

	printf("El hilo empieza a crearse");
	while (i < n_lines)
	{
		fd = open("/home/cristian/Escritorio/42_Philosophers/Examples/pruebas.txt", O_WRONLY|O_APPEND);
		if(!fd)
			write(1, "no",2);
		write(fd, buf, sizeof(buf)-1);
		close(fd);
		i++;
	}

}

int main (int argc, char **argv)
{
	pthread_t	thread_1;
	int			value = atoi(argv[1]);

	if(pthread_create(&thread_1, NULL, thread_routine, &value) != 0)
		return(-1);
	pthread_join(thread_1, NULL);
	return(0);
}