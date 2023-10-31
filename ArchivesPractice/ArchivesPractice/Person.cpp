#include "Person.h"

Person::Person() {}

Person::Person(string newName, string newLastName, string newGender, int newAge)
{
	this->name = newName;
	this->lastName = newLastName;
	this->gender = newGender;
	this->age = newAge;
}

void Person::savePersons(FileManager* manager, Person* persons, int personsNumb)
{
	string fileName = "Persons.txt";
	int personAttributtes = 4;

	string* stringLinesData = new string[personsNumb];

	for (int index = 0; index < personsNumb; index++) {
		stringLinesData[index] = "";

		string personName = persons[index].getName();
		string personLastName = persons[index].getLastName();
		string personGender = persons[index].getGender();
		string personAgeInString = to_string(persons[index].getAge());

		stringLinesData[index] = personName + "," + personLastName + "," + personGender
			+ "," + personAgeInString;
	}

	manager->save(fileName, stringLinesData, personsNumb);
	delete[] stringLinesData;
}

Person* Person::loadPersons(FileManager* manager, int numberOfPersons)
{
	string fileName = "Persons.txt";
	Person* persons = new Person[numberOfPersons];

	string* data = manager->load(fileName);

	if (data) {
		for (int index = 0; index < numberOfPersons; index++) {
			istringstream iss(data[index]);

			string personName;
			string personLastName;
			string personGender;
			string stringPersonAge;

			if (iss) {//esto asume que todas las llamadas a getline tendrán éxito, es decir, que siempre encontrarán comas para separar los campos y que los datos en el archivo están bien formateados. 
				getline(iss, personName, ',');
				getline(iss, personLastName, ',');
				getline(iss, personGender, ',');
				getline(iss, stringPersonAge, ',');
				int personAge = stoi(stringPersonAge);
				persons[index] = Person(personName, personLastName, personGender, personAge);
			}
			/*if (getline(iss, personName, ',') &&
				getline(iss, personLastName, ',') &&
				getline(iss, personGender, ',') &&
				getline(iss, stringPersonAge)) {
				int personAge = stoi(stringPersonAge);
				persons[index] = Person(personName, personLastName, personGender, personAge);
			}*/
			else {
				// Manejo de error en caso de datos incorrectos en el archivo.
				cerr << "Error al leer los datos de la persona en la línea " << (index + 1) << endl;
				// Puedes decidir cómo manejar este error según tus necesidades.
			}
		}
	}
	return persons;
}


void Person::print()
{
	cout << "Name: " << name << endl
		<< "Last Name: " << lastName << endl
		<< "Gender: " << gender << endl
		<< "Age: " << age << endl << endl;
}

void Person::setName(string newName)
{
	this->name = newName;
}

void Person::setLastName(string newLastName)
{
	this->lastName = newLastName;
}

void Person::setGender(string newGender)
{
	this->gender = newGender;
}

void Person::setAge(int newAge)
{
	this->age = newAge;
}

string Person::getName()
{
	return name;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getGender()
{
	return gender;
}

int Person::getAge()
{
	return age;
}
