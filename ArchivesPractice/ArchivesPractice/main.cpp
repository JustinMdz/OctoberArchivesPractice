#include <iostream>
#include "RandomNumbers.h"
#include "FileManager.h"
#include "Person.h"
#include"CarInfo.h"
using namespace std;
const static int ROWS = 3;
const static int COLUMMNS = 3;

int main() {

	FileManager* fileManager = new FileManager();

	//parte carros

	CarInfo* cars[3];

	cars[0] = (new CarInfo("Toyota", "BRZ", "BLACK", "GOOD", "WRD", "SUPER",
		2,4,2018,65000,12500,85000));
	cars[1] = (new CarInfo("Mazda", "RX-8", "WHITE", "BAD", "AWD", "DIESEL",
		2, 2, 1990, 35000, 85000, 60000));
	cars[2] = (new CarInfo("NISSAN", "GTR-R35", "BLUE", "EXCELENT", "FWD", "SUPER",
		2, 2, 2020, 70000, 25000, 180000));

	for (int index = 0; index < 3; index++) {
		cars[index]->print();
	}
	cars[0]->saveCar(fileManager);
	cars[1]->saveCar(fileManager);
	cars[2]->saveCar(fileManager);




	// parte personas
	//Person* persons[3];
	//Person* newPersons[3];

	//persons[0] = new Person("Justin", "Mendez", "H", 18);
	//persons[1] = new Person("David", "Castro", "T", 18);
	//persons[2] = new Person("Keyla", "Lopez", "M", 18);

	//for (int index = 0; index < 3; index++) {
	//	persons[index]->print();
	//}

	//persons[0]->savePerson(fileManager);
	//persons[1]->savePerson(fileManager);
	//persons[2]->savePerson(fileManager);


	//for (int index = 0; index < 3; index++) {
	//	newPersons[index]->loadPerson(fileManager);
	//	//newPersons[index]->print();
	//}

	//cout << newPersons[0];


	//parte de la matrix

	//RandomNumbers* randomMatrix = new RandomNumbers(ROWS,COLUMMNS);
	//RandomNumbers* matrixToChargue = new RandomNumbers(ROWS, COLUMMNS);
	//randomMatrix->fillWithRandomNumbers();

	//randomMatrix->print();
	//matrixToChargue->print();
	////randomMatrix->saveMatrix(fileManager);

	//matrixToChargue->loadMatrix(fileManager);
	//cout << "Deberia ser la misma monda"<<endl<<endl;
	//matrixToChargue->print();

	delete fileManager;
	return 0;
}