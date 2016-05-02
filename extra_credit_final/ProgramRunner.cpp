#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{

	string theString;
	pid_t pid = fork();

	if(pid == 0)
	{

		for(int j = 0; j < 10; j++)
			cout << "Child: " << j << endl;

	}
	else
	{

		wait(&pid);
		for(int i = 0; i < 10; ++i)
		{

			cout << "Parent: " << i << endl;;

		}

	}

	return 0;

}
