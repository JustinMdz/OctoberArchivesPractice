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
	void save(string&,string*,int);
	int countLines(string&);
	string* load(string&);
};