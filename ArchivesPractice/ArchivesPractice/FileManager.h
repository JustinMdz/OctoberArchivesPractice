#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class FileManager
{
private:

public:
	FileManager();
	void save(string*,string,int);
	string* load(const string&,int);
	int getLineToRead(string&);
};