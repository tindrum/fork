// parallel.cpp
// CS 351 Assignment 1
// Our team is:
// Joshua Edmonds
// Daniel Henderson
// Nikita
//
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
  
	cout << "basic stub" << endl;
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

	while (!urlFile.eof()) \
	{
		getline(urlFile, textLine);

		childCount++;
		int pid = fork();
		if (pid == 0)
		{
			execlp("usr/bin/wget", "wget", textLine, NULL);
		}
		// process each line
		cout << textLine << endl;
	}
	while (childCount > 0)
	{
		wait(NULL);
		childCount--;
	}
  
  return 0;
}