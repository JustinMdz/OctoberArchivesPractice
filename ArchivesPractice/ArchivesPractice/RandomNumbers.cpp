#include "RandomNumbers.h"

RandomNumbers::RandomNumbers(int newRows, int newColummns)
{
	this->rows = newRows;
	this->colummns = newColummns;

	matrix = new int* [newRows];
	for (int index = 0; index < newRows; index++) {
		matrix[index] = new int[newColummns];
	}

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < colummns; index2++) {
			matrix[index1][index2] = 0;
		}
	}
}

void RandomNumbers::fillWithRandomNumbers()
{
	int randomNumberLimit = 20;
	srand(static_cast<unsigned>(time(nullptr)));

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < colummns; index2++) {
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
	return this->colummns;
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
	int stringsInLine = colummns;

	string* stringInMatrixRowToSave;
	stringInMatrixRowToSave = new string[colummns];

	for (int index1 = 0; index1 < rows; index1++) {
		for (int index2 = 0; index2 < colummns; index2++) {
			
			stringInMatrixRowToSave[index2] =to_string(matrix[index1][index2]);
		}
		manager->save(stringInMatrixRowToSave, fileName, stringsInLine);
	}
}

void RandomNumbers::loadMatrix(FileManager* manager)
{
	string fileName = "Matrix.txt";
	int columnsToRead = colummns; // Corregido el nombre de la variable
	string* strings;

	for (int index1 = 0; index1 < rows; index1++) {
		strings = manager->load(fileName, columnsToRead);

		if (strings != nullptr) {
			for (int index2 = 0; index2 < colummns; index2++) {
				matrix[index1][index2] = stoi(strings[index2]);
			}
			// Libera la memoria asignada a 'strings' después de usarla
			delete[] strings;
		}
		else {
			// Manejar el error de carga del archivo
			// Puede ser una buena idea lanzar una excepción o tomar medidas adecuadas en caso de error
		}
	}
}

void RandomNumbers::print()
{
	cout << "\n\n";
	for (int indexRows = 0; indexRows < rows; indexRows++) {
		for (int indexColummns = 0; indexColummns < colummns; indexColummns++) {
			cout << matrix[indexRows][indexColummns] << "  ";
		}
		cout << endl;
	}
}