#include "RandomNumbers.h"

RandomNumbers::RandomNumbers(int newRows, int newColummns)
{
	this->rows = newRows;
	this->columns = newColummns;

	matrix = new int* [newRows];
	for (int index = 0; index < newRows; index++) {
		matrix[index] = new int[newColummns];
	}

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < columns; index2++) {
			matrix[index1][index2] = 0;
		}
	}
}

void RandomNumbers::fillWithRandomNumbers()
{
	int randomNumberLimit = 9;
	srand(static_cast<unsigned>(time(nullptr)));

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < columns; index2++) {
			matrix[index1][index2] = (rand() % randomNumberLimit) + 1;
		}
	}
}


int RandomNumbers::getRows()
{
	return this->rows;
}

int RandomNumbers::getColumms()
{
	return this->columns;
}

int RandomNumbers::getMatrixNumberPos(int index1, int index2) {
	return this->matrix[index1][index2];
}

int* RandomNumbers::getMatrixRow(int indexPosition)
{
	return matrix[indexPosition];
}

void RandomNumbers::saveMatrix(FileManager* manager) {
	string fileName = "Matrix.txt";
	string* stringLinesData = new string[rows];

	for (int index1 = 0; index1 < rows; index1++) {
		stringLinesData[index1] = "";

		for (int index2 = 0; index2 < columns; index2++) {
			stringLinesData[index1] += to_string(matrix[index1][index2]);

			if (index2 < columns - 1) {
				stringLinesData[index1] += ",";
			}
		}
	}
	// Guardar el archivo y manejar posibles errores
	manager->save(fileName, stringLinesData, columns);

	// Limpieza de la memoria dinámica (importante)
	delete[] stringLinesData;
}


void RandomNumbers::loadMatrix(FileManager* manager)
{
	string fileName = "Matrix.txt";
	string* data = manager->load(fileName);
	int number;
	char comma;

	for (int index1 = 0; index1 < rows; index1++) {
		istringstream iss(data[index1]);
		for (int index2 = 0; index2 < columns; index2++) {
			iss >> number >> comma;
			if (iss) {
				matrix[index1][index2] = number;
			}
		}
	}
}

//void RandomNumbers::loadMatrix(FileManager* manager)
//{
//	string fileName = "Matrix.txt";
//	string* data = manager->load(fileName);
//	int firstRowNumb, SecondRowNumb, thirdRowNumb;
//	char comma;
//
//	for (int index = 0; index < rows; index++) {
//		istringstream iss(data[index]);
//		iss >> firstRowNumb >> comma >> SecondRowNumb >> comma >> thirdRowNumb;
//		if (iss) {
//			matrix[index][0] = firstRowNumb;
//			matrix[index][1] = SecondRowNumb;
//			matrix[index][2] = thirdRowNumb;
//		}
//	}
//}

void RandomNumbers::print()
{
	cout << "\n\n";
	for (int indexRows = 0; indexRows < rows; indexRows++) {
		for (int indexColummns = 0; indexColummns < columns; indexColummns++) {
			cout << matrix[indexRows][indexColummns] << "  ";
		}
		cout << endl;
	}
}