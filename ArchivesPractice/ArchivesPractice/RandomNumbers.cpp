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
	int randomNumberLimit = 20;
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
	return matrix[indexPosition];;
}

void RandomNumbers::saveMatrix(FileManager* manager)
{
	string fileName = "Matrix.txt";
	int stringsInLine = columns;

	string* stringInMatrixRowToSave;
	stringInMatrixRowToSave = new string[columns];

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < columns; index2++) {

			stringInMatrixRowToSave[index2] = to_string(matrix[index1][index2]);
		}
		manager->save(stringInMatrixRowToSave, fileName, stringsInLine);
	}
}

void RandomNumbers::loadMatrix(FileManager* manager)
{
	
}

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