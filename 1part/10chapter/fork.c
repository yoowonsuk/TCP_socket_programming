#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char *argv[])
{
	pid_t pid;
	int lval = 20;
	gval++, lval++;

	pid = fork();
	if(!pid)
		gval+=2, lval+=2;
	else
		gval -=2, lval-=2;

	if(!pid)
		printf("Child Proc: [%d, %d] \n", gval, lval);
	else
		printf("Parent Proc: [%d, %d] \n", gval, lval);
	return 0;
}
