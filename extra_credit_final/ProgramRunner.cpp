#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{

	string theString;
	pid_t pid = fork();

	if(pid == 0)
	{

		theString = "Child";

	}
	else
	{

		theString = "Parent";
		wait();

	}

	cout << theString;

	return 0;

}
