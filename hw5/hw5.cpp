/*

	Kuba Gasiorowski, NETID: kgasiorowski, kuba.gasiorowski@stonybrook.edu
	
	Main driver program for the ListRecords class.
	Allows the user to interact with a list of books.

*/

#include <string>
#include <iostream>
#include "ListRecords.h"
#include <algorithm>
void printMenu()
{

	cout << "Select an option from the following menu:" << endl;
	cout << "1)Insert a new book into the list" << endl;
	cout << "2)Print the info of a specific book by ISBN number" << endl;
	cout << "3)Print the list sorted by ISBN" << endl;
	cout << "4)Print the list sorted alphabetically by title" << endl;
	cout << "5)Print this menu once again" << endl;
	cout << "6)Quit the program" << endl;

}

int main(){
	
    string inputFileName;

    cout << "Enter an input file name: ";
    cin >> inputFileName;

    try{

        ListRecords myList(inputFileName);

        bool finished = false;
        printMenu();
        string cmd;

        while(!finished){

            cout << ">";
            cin >> cmd;

            if(cmd.compare("6") == 0 ||
               cmd.compare("q") == 0 ||
               cmd.compare("Q") == 0)
            {

                finished = true;

            }else if(cmd.compare("1") == 0){

                //Inserts a new book into the list
                string title, author, publisher;
                int ISBN;

                cout << "Enter the book title: ";
                cin >> title;
                cout << "Enter the author: ";
                cin >> author;
                cout << "Enter the publisher: ";
                cin >> publisher;
                cout << "Enter the ISBN: ";
                cin >> ISBN;

                try{

                        myList.insertBookInfo(BookRecord(title, author, publisher, ISBN));

                }catch(const char* msg){

                        cout << "Error: " << msg << endl;

                }

            }else if(cmd.compare("2") == 0){
                //Print the info of a specific book by ISBN
                int ISBNtoFind;

                cout << "Enter a ISBN number: ";
                cin >> ISBNtoFind;

                if(myList.containsISBN(ISBNtoFind))
                        myList.printBookInfo(ISBNtoFind);
                else
                        cout << "ISBN not found!" << endl << endl;

            }else if(cmd.compare("3") == 0){

                //Prints the list of records sorted by ISBN
                myList.printListByISBN();

            }else if(cmd.compare("4") == 0){

                //Prints the list of records sorted by Title
                myList.printListByTitle();

            }else if(cmd.compare("5") == 0){

                //Prints the menu once again
                printMenu();

            }
            else 
                cout << "Invalid command entered" << endl;


        }

    }catch(const char* msg){

        cerr << "Error: " << msg << endl;

    }

    return 0;

}
