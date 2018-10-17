#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void makeDaemon()
{
	pid_t pid;
	if((pid = fork()) < 0)
	{
		perror("error:fork");
		exit(EXIT_FAILURE);
	}
	else if(pid > 0)
	{
		exit(EXIT_SUCCESS);
	}

	setsid();
	chdir("/");
	umask(0);
}

int main(int argc, char ** argv)
{
	char host[60];
	if(argc == 1)
	{
		gethostname(host, sizeof(host));
	}
	else if(argc == 2)
	{
		strcpy(host, argv[1]);
	}
	else
	{
		printf("Usage: myftpd [ hostname | IP_address ]\n");
		exit(EXIT_FAILURE);
	}
}
