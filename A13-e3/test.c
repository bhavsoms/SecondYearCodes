#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	printf("Hello there\n");
	return 0;
}
