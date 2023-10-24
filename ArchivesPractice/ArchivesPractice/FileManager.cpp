#include "FileManager.h"

FileManager::FileManager() {}

void FileManager::save(string* stringsInLineToSave, string fileName, int stringsInLine)
{
	try {
		ofstream ouputArchive(fileName, ios::app);//guardas cosas sin sobreescribirlas->ofstream ouputArchive(fileName, ios::app);
		for (int index = 0; index < stringsInLine; index++) {
			ouputArchive << stringsInLineToSave[index] << " ";
		}
		ouputArchive << endl;
		ouputArchive.close();
		cout << "Datos esctritos adecuadamente." << endl;
	}

	catch (const exception& exception) {
		cerr << "Error al cargar el archivo de escritura" << exception.what() << endl;
	}
}

string* FileManager::load(string& fileName, int linesToRead)
{
	try {
		string* linesToInput;
		ifstream inputArchive(fileName);

		linesToInput = new string[linesToRead];
		string line;
		int index = 0;
		while (getline(inputArchive, line)) {
			linesToInput[index] = line;
			index++;
		}

		inputArchive.close();

		return linesToInput;
	}
	catch (const exception& exception) {
		cerr << "Error al cargar el archivo de lectura: " << exception.what() << endl;
	}

	return nullptr;  // Return nullptr in case of an error
}

int FileManager::getLineToRead(string& filename)
{
	int countLines = 0;
	try {
		ifstream inputArchive(filename);
		string line;
		while (getline(inputArchive, line)) {
			countLines++;
		}
		inputArchive.close();
		cout << "Lineas contadas con exito: ";
		return countLines;
	}
	catch (const exception& ex) {
		cerr << "Error al cargar el archivo de lectura: " << ex.what() << endl;
		return countLines = 0;
	}
}