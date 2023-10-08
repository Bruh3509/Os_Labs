#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void signalHandler(int signalno)
{}

int main(int argc, char** argv)
{
	pid_t cpid, w;
	int wstatus;

	cpid = fork();
	if (cpid == -1) {
		perror("fork\n");
		exit(EXIT_FAILURE);
	}

	if (cpid == 0) {
		sleep(5);
		return 1;
	} else {
		signal(SIGINT, signalHandler);
		signal(SIGTERM, signalHandler);
		w = wait(&wstatus);
		if (w == -1) {
			perror("waitpid\n");
			exit(EXIT_FAILURE);
		}

		if (WIFEXITED(wstatus))
			printf("\nNormal exit with status %d\n", WEXITSTATUS(wstatus));
		else if (WIFSIGNALED(wstatus))
			printf("\nKilled by signal %d\n", WTERMSIG(wstatus));
		else if (WIFSTOPPED(wstatus))
			printf("\nStopped by signal %d\n", WSTOPSIG(wstatus));
		else if (WIFCONTINUED(wstatus))
			printf("\nContinued\n");
	}
	return 0;
}
