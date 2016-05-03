#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int execute(string);
void printmenu();

int main(){

	//Specifies the path for each program to run
	const string firstProgram = "/usr/bin/gnome-terminal -e ./testprogram";
	const string secondProgram = "/usr/lib/firefox/firefox"; 
	const string thirdProgram = "/usr/lib/gnome-character-map"; 
	const string fourthProgram = "/usr/bin/gnome-calculator";

	bool finished = false;
	string cmd;

	printmenu();

	while(!finished){
		
		cout << ">";
		cin >> cmd;
		
		if(cmd.compare("1") == 0)
		{

			execute(firstProgram);

		}
		else if(cmd.compare("2") == 0)
		{

			execute(secondProgram);

		}	
		else if(cmd.compare("3") == 0)
		{

			execute(thirdProgram);

		}
		else if(cmd.compare("4") == 0)
		{

			execute(fourthProgram);

		}
		else if(cmd.compare("5") == 0)
		{
	
			finished = true;
		
		}

	}	


	return 0;

}

void printmenu(){

	cout << "Menu:" << endl;
	cout << "1: TestPrgrm (local program)" << endl;
	cout << "2: FireFox" << endl;
	cout << "3: Character map or something" << endl;
	cout << "4: Calculator" << endl;
	cout << "5: Exit this program" << endl;

}

int execute(string cmd){

	pid_t pid = vfork();

	if(pid == 0){

	//Child process code


		/*
		if(cmd.compare("/usr/bin/gnome-terminal -e ./testprogram") == 0){

			execl("/usr/bin/gnome-terminal", "/usr/bin/gnome-terminal", "-e", "./testprogram", NULL);	
			
		}else{

			execl(cmd.c_str(), cmd.c_str(), NULL);
			
		}
		*/
		system(cmd.c_str());
		exit(0);//Ends this process

	}

}
