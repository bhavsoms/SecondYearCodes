#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	if (pid==0)
	{
		printf("Child Process and parent Process ID:\n\n");
		printf("ChildID=%d,parentid=%d\n\n",getpid(),getppid());
	}
	else if (pid >0)
	{
		printf("Parent Process ID:\n\n");
		printf("parentid=%d\n\n",getpid());
	}
	return 0;	
}
