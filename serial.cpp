// serial.cpp
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
#include <ctime>





using namespace std;



int main (int argc, char const *argv[])
{
  cout << "getting start time" << endl;
  double startTime, endTime, timeDiff;
  startTime = time(NULL);

  cout << "serial file getter program" << endl;
  // open a file for reading
  
  ifstream urlFile(argv[1]);

  if (urlFile.is_open()) {
  	cout << "url file opened successfully" << endl;
  } else {
  	cout << "couldn't open url file. quitting." << endl;
  	return -1;
  }


  // read each line
  string textLine;

  while ( !urlFile.eof() ) {
  	getline(urlFile, textLine);

  	int pid = fork();
  	if (pid == 0)
  	{
      cout << "forked, trying to wget the file " << textLine << endl;
  		execlp("/usr/bin/wget", "wget", textLine.c_str(), NULL);
  	}
  	else
  	{
      cout << "Waiting" << endl;
  		wait(NULL);
  	}


    cout << "getting end time" << endl;
    endTime = time(NULL);
    cout << "Time difference is: " ;
    timeDiff = difftime(endTime, startTime);
    cout << timeDiff << endl;
  }



  // wait for fork to return

  return 0;
}