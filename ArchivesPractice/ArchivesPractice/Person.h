#pragma once
#include "FileManager.h"
#include <string>
class Person
{
private:
	string name;
	string lastName;
	string gender;
	int age;

public:
	Person();
	Person(string,string,string,int);
	void savePersons(FileManager*,Person*,int);
	Person* loadPersons(FileManager*,int);
	void print();

	void setName(string);
	void setLastName(string);
	void setGender(string);
	void setAge(int);

	string getName();
	string getLastName();
	string getGender();
	int getAge();
};