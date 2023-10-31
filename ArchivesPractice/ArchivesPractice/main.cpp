#include <iostream>
#include "RandomNumbers.h"
#include "FileManager.h"
#include "Person.h"
#include"CarInfo.h"
using namespace std;

int main() {

	FileManager* fileManager = new FileManager();

	//parte personas
	int personNumb = 3;
	Person* persons = new Person[personNumb];

	Person aux;

	persons[0] = Person("Justin", "Mendez", "H", 18);
	persons[1] = Person("Juan", "Meca", "T", 18);
	persons[2] = Person("Keyla", "Lopez", "M", 18);

	aux.savePersons(fileManager, persons, personNumb);

	Person* newPersons = aux.loadPersons(fileManager,personNumb);

	for (int index = 0; index < personNumb; index++) {
		newPersons[index].print();
		persons[index].print();
	}


		/*parte de la matrix*/

	/*RandomNumbers* randomMatrix = new RandomNumbers(ROWS, COLUMMNS);
	RandomNumbers* matrixToChargue = new RandomNumbers(ROWS, COLUMMNS);
	randomMatrix->fillWithRandomNumbers();

	randomMatrix->print();
	matrixToChargue->print();
	randomMatrix->saveMatrix(fileManager);
	matrixToChargue->loadMatrix(fileManager);
	cout << "La otra:" << endl;
	matrixToChargue->print();
	delete randomMatrix;
	delete matrixToChargue;*/
	////parte carros

	//CarInfo* cars[3];

	//cars[0] = (new CarInfo("Toyota", "BRZ", "BLACK", "GOOD", "WRD", "SUPER",
	//	2, 4, 2018, 65000, 12500, 85000));
	//cars[1] = (new CarInfo("Mazda", "RX-8", "WHITE", "BAD", "AWD", "DIESEL",
	//	2, 2, 1990, 35000, 85000, 60000));
	//cars[2] = (new CarInfo("NISSAN", "GTR-R35", "BLUE", "EXCELENT", "FWD", "SUPER",
	//	2, 2, 2020, 70000, 25000, 180000));

	//for (int index = 0; index < 3; index++) {
	//	cars[index]->print();
	//}
	//cars[0]->saveCar(fileManager);
	//cars[1]->saveCar(fileManager);
	//cars[2]->saveCar(fileManager);



	delete fileManager;
	return 0;
}