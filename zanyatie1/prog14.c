#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	printf("count = %d\n", argc);
	for (int i = 0; i< argc;i++)
	{
		printf("%d: %s\n", i+1, argv[i]);
	}
	for (int i=0;envp[i] != NULL;i++)
	{
		printf("envp[%d] = %s\n", i+1, envp[i]);	
	}
	return 0;
}
