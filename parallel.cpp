// parallel.cpp
// CS 351 Assignment 1
// Our team is:
// Joshua Edmonds
// Daniel Henderson
// Nikita
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main (int argc, char const *argv[])
{
	cout << "Parallel file getter program" << endl;
	// open a file for reading

	ifstream urlFile(argv[1]);

	if (urlFile.is_open()) {
		cout << "url file opened successfully" << endl;
	}
	else {
		cout << "couldn't open url file. quitting." << endl;
		return -1;
	}


	// read each line
	string textLine;
	int childCount = 0;

	while (!urlFile.eof()) 
	{
		getline(urlFile, textLine);

		childCount++;
		int pid = fork();
		if (pid == 0)
		{
			if ( execlp("/usr/bin/wget", "wget", textLine.c_str(), NULL) < 0)
			{
				cout << "execlp failed to work" << endl;
			}
		}
		else if (pid < 0)
		{
    		cout << "error creating fork" << endl;
    		perror("fork");
    		exit(-1);
		}
	}
	while (childCount > 0)
	{
		wait(NULL);
		childCount--;
	}
  


    return 0;
}