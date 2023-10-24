#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManager
{
private:

public:
	FileManager();
	void save(string*,string,int);
	string* load(string&,int);
	int getLineToRead(string&);
};