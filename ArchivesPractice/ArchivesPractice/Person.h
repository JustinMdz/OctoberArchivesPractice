#pragma once
#include "FileManager.h"
class Person
{
private:
	string name;
	string lastName;
	string gender;
	int age;

public:
	Person(string,string,string,int);
	void savePerson(FileManager*);
	void loadPerson(FileManager*);
	void print();
};