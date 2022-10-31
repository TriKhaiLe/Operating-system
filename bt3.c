#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	// fork mot child process
	pid = fork();
	
	// fork khong thanh cong
	if (pid < 0)
	{
		printf("Fork failed");
		return 1;
	}
	
	// child process
	else if (pid == 0)
	{
		execlp("/bin/ls","ls",NULL);
	}
	
	// parent process
	else
	{
		// cho child process hoan thanh
		wait(NULL);
		printf("Complete child process");
	}
	

return 0;
}




