#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int loop_forever = 1;

void on_sigint1()
{
	printf("\nYou are pressed CTRL+C! Goodbye!\n");
	loop_forever = 0;
}

void on_sigint2()
{
	exit(0);
}

int main()
{	
	// cau a
	printf("Welcome to IT007, I am 21521565!\n");
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{	
		// cau b
		signal(SIGINT, on_sigint2);
		execl("/usr/bin/gedit", "gedit", "abcd.txt", NULL);		
	}
	
	else
	{
		// cau c
		signal(SIGINT, on_sigint1);
		
		while(loop_forever){}
	}
	
	return 0;
}
