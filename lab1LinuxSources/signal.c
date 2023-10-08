#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigHandler(int);

int main(int argc, char** argv)
{
	signal(SIGINT, sigHandler);
	signal(SIGTERM, sigHandler);
	while(1);
	return 0;
}

void sigHandler(int signalno)
{
	switch (signalno) {
		case SIGINT:
			printf("\nSIGINT %d\n", signalno);
			break;
		case SIGTERM:
			printf("\nSIGTERM %d\n", signalno);
			break;
		default:
			printf("\nAnother signal\n");
			break;
	}

	exit(0);
}
