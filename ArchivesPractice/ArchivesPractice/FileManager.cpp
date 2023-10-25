#include "FileManager.h"

FileManager::FileManager() {}

void FileManager::save(string* stringsInLineToSave, string fileName, int stringsInLine)
{
	try {
		ofstream ouputArchive(fileName,ios::app);//guardas cosas sin sobreescribirlas->ofstream ouputArchive(fileName, ios::app);
		for (int index = 0; index < stringsInLine; index++) {
			ouputArchive << stringsInLineToSave[index] << ",";
		}
		ouputArchive << endl;
		ouputArchive.close();
		cout << "Datos esctritos adecuadamente." << endl;
	}

	catch (const exception& exception) {
		cerr << "Error al cargar el archivo de escritura" << exception.what() << endl;
	}
}

string* FileManager::load(const string& fileName, int linesToRead)
{
	try {
		string* linesToInput = new string[linesToRead];
		ifstream inputArchive(fileName);

		if (!inputArchive.is_open()) {
			throw runtime_error("No se pudo abrir el archivo.");
		}

		string line;
		int linesRead = 0;

		while (linesRead < linesToRead && getline(inputArchive, line)) {
			linesToInput[linesRead] = line;
			linesRead++;
		}

		inputArchive.close();
		return linesToInput;
	}
	catch (const exception& exception) {
		cerr << "Error al cargar el archivo de lectura: " << exception.what() << endl;
	}

	return nullptr;  // Retorna nullptr en caso de error
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