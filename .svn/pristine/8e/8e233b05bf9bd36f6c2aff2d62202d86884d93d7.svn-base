#ifndef FLAGSCONTAINER_H
#define FLAGSCONTAINER_H

#include <iostream>
using namespace std;

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

class FlagsContainer{

	private:
	
		bool *tab;
		const static short int ARRAY_SIZE = 16;
		
	public:
	
		FlagsContainer();
		~FlagsContainer();
		
		void unlockLevel(int lvl);
		bool* getArrayOfFlags();
		
		bool readArrayFromFile(QString player);
		bool saveArrayToFile(QString player);
		
		int getLenghtOfPath();
		bool getStateOfFlag(int lvl);
		
		QString printToString();
};

#endif