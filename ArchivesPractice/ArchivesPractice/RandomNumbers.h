#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include "FileManager.h"

class RandomNumbers
{
private:
	int** matrix;
	int rows;
	int colummns;

public:
	RandomNumbers(int,int);
	void fillWithRandomNumbers();
	int getRows();
	int getColumms();
	int getMatrixNumberPos(int, int);
	int* getMatrixRow(int);
	void print();
	void saveMatrix(FileManager*);
	void loadMatrix(FileManager*);
};