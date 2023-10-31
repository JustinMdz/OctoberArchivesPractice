#include "FileManager.h"

FileManager::FileManager() {}

void FileManager::save(string& fileName, string* dataLines, int lines) {
	try {
		ofstream ouputArchive(fileName);
		if (!ouputArchive.is_open()) {
			throw runtime_error("Error al abrir el archivo para escritura");
		}

		for (int indexDataPerLine = 0; indexDataPerLine < lines; indexDataPerLine++) {
			ouputArchive << dataLines[indexDataPerLine] << ";" << endl;
		}
	}
	catch (const exception& ex) {
		cerr << "Excepción atrapada: " << ex.what() << endl;
	}
}

int FileManager::countLines(string& fileName)
{
	try {
		ifstream inputArchive(fileName);
		if (!inputArchive.is_open()) {
			throw runtime_error("Error al abrir el archivo de lectura");
		}
		int lines = 0;
		string line;
		while (getline(inputArchive, line)) {
			lines++;
		}
		return lines;
	}
	catch (const exception& ex) {
		cerr << "Excepción atrapada: " << ex.what() << endl;
	}
	return 0;
}

string* FileManager::load(string& fileName)
{
	try {
		ifstream inputArchive(fileName);
		if (!inputArchive.is_open()) {
			throw runtime_error("Error al abrir el archivo de lectura");
		}
		string* data = new string[countLines(fileName)];
		string line;
		int index = 0;
		while (getline(inputArchive, line)) {
			data[index] = line;
			cout << data[index];
			index++;
		}
		return data;
	}
	catch (const exception& ex) {
		cerr << "Excepción atrapada: " << ex.what() << endl;
	}
	return nullptr;
}