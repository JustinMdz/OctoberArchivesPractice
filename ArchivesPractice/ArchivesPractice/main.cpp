#include <iostream>
#include "RandomNumbers.h"
#include "FileManager.h"
using namespace std;
const static int ROWS = 3;
const static int COLUMMNS = 3;

int main() {

	FileManager* fileManager = new FileManager();
	RandomNumbers* randomMatrix = new RandomNumbers(ROWS,COLUMMNS);
	RandomNumbers* matrixToChargue = new RandomNumbers(ROWS, COLUMMNS);
	randomMatrix->fillWithRandomNumbers();

	randomMatrix->print();
	matrixToChargue->print();
	//randomMatrix->saveMatrix(fileManager);

	matrixToChargue->loadMatrix(fileManager);
	cout << "Deberia ser la misma monda"<<endl<<endl;
	matrixToChargue->print();
	
	delete fileManager;
	return 0;
}