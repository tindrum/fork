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
#include <sys/wait.h>




using namespace std;


string fullURLFromPartial(string partialURL){
	// builds a full url from an href link 
	// in an APOD web page link
	string siteURL = "http://apod.nasa.gov/apod";

	return siteURL + "/" + partialURL;
}


string findImageURL(string urlText){
	string fullGetCommand = "wget -r -np -A .txt " + urlText;

	// FILE* file = peopen(strcat("wget -r -np -a .txt ", urlText.c_str()));
	// not at all sure how to use wget inside a C++ program.

	return "your url here";
}

int main (int argc, char const *argv[])
{
  cout << "basic stub" << endl;
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
		execlp("usr/bin/wget", "wget", textLine.c_str(), NULL);
	}
	else
	{
		wait(NULL);
	}
  	// process each line
  	cout << textLine << endl;
  }



  // wait for fork to return

  return 0;
}