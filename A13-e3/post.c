#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	pid_t qid = fork();
	pid_t rid = fork();
	pid_t sid = fork();
	if (pid==0)
	{
		printf("Child\n");
	}
	else if (pid>0)
	{
		printf("Parent\n");
	}
	return 0;	
}
