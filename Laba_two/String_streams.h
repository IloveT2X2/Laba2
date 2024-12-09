#ifndef STRING_STREAMS
#define STRING_STREAMS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StringSt
{
public:
	StringSt();
	~StringSt();

	string path = "myFile.txt";

	fstream fout;

private:

};
#endif STRING_STREAMS