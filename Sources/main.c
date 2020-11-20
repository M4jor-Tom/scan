#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

bool keepScanning;
int _argc;
char **_argv;

void scan();
void stopScan();

int main(int argc, char *argv[])
{
	//Globalize for signal functions
	_argc = argc;
	_argv = argv;
	
	//Signal init
	keepScanning = true;
	signal(SIGINT, stopScan);
	signal(SIGALRM, scan);
	alarm(1);

	//Entering loop process
	while(keepScanning);

	//Ending process
	system("clear");
	return 0;
}

void stopScan()
{
	keepScanning = false;
}

void scan()
{
	system("clear");
	
	char launch[256] = "\0";

	//Constructing command call
	int i;
	for(i = 1; i < _argc; i++)
	{
		if(i > 1)
			strcat(launch, " ");
		strcat(launch, _argv[i]);
	}
	
	//Executing loop call
	system(launch);

	//Preparing next call
	alarm(1);
}
