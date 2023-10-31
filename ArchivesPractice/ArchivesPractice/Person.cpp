#include "Person.h"

Person::Person(string newName, string newLastName, string newGender, int newAge)
{
	this->name = newName;
	this->lastName = newLastName;
	this->gender = newGender;
	this->age = newAge;
}

void Person::savePerson(FileManager* manager)
{
	string personsFileName = "Persons.txt";
	int personDataPerLine = 4;
	string* personData;
	personData = new string[personDataPerLine];

	personData[0] = name;
	personData[1] = lastName;
	personData[2] = gender;
	personData[3] = to_string(age);

	//manager->save(personData, personsFileName, personDataPerLine);
}

void Person::loadPerson(FileManager* manager)
{
	

}

void Person::print()
{
	cout << "Name: " << name << endl
		<< "Last Name: " << lastName << endl
		<< "Gender: " << gender << endl
		<< "Age: " << age << endl << endl;
}
