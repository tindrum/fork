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





using namespace std;



int main (int argc, char const *argv[])
{

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
  		if (execlp("/usr/bin/wget", "wget", textLine.c_str(), NULL) < 0)
      {
        cout << "execlp wasn't able to run" << endl;
      }
  	}
    else if ( pid < 0){
      cout << "failed to fork process" << endl;
        perror("fork");
        exit(-1);
    }
  	else
  	{
      cout << "Waiting" << endl;
  		wait(NULL);
  	}


  }



  // wait for fork to return

  return 0;
}
