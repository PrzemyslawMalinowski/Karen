#include "flagscontainer.h"
/**
*@name
*	FlagsContainer
*
*	Konstruktor klasy obs³uguj¹cej flagi.
*	Tworzy on nowy obiekt (tablicê flag) i 
*	wype³nia j¹ samymi false'ami z wyj¹tkiem flagi[0]
*
*	NALE¯Y PAMIÊTAÆ, ¯E KLASA PRZECHOWUJE STAN FLAG, a nie 
*	same flagi. nale¿y te¿ pamiêtaæ, ¿e stan flagi n-tej jest reprezentowana
* 	przez komórkê tab[n-1]
*/

FlagsContainer::FlagsContainer()
{
	tab = new bool[ARRAY_SIZE];
}

/**
*@name
*	~FlagsContainer
*
*	Destruktor usuwaj¹cy tablicê
*/

FlagsContainer::~FlagsContainer()
{
	delete tab;
}

/**
*@name
*	unlockLevel
*@param
*	int lvl - 	jak¹ flagê odpowiadaj¹c¹za jaki level nale¿y
*				odblokowaæ
*@return
*	void
*
*	Metoda odpowiadaj¹ca za ustawienie flagi na to, ¿e bêdzie mo¿na na ni¹ klikn¹æ
*/

void FlagsContainer::unlockLevel(int lvl)
{
	tab[lvl - 1] = true;
}

/**
*@name
*	getArrayOfFlags
*@param
*	void
*@return
*	bool* - wskaŸnik do prywatnej tablicy statusów flag
*
*	Zwraca tablicê odpowiadaj¹c¹ za statusy flag
*/

bool* FlagsContainer::getArrayOfFlags()
{
	return tab;
}

/**
*@name
*	readArrayFromFile
*@param
*	QString player - nazwa gracza
*	
*@return
*	true - gdy wczytano bez cudów
*	false w innym przypadku
*
*	Metoda odpowiadaj¹ca za odczyt stanu flag z odpowiedniego 
*	pliku "nazwa_gracza.dat" z folderu ./users/flags
*/

bool FlagsContainer::readArrayFromFile(QString player)
{
	int buffer;
	QString filename = "./users/flags/" + player + ".dat";
	
	QFile file(filename);
	
	if ( file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream( &file );
		
		for(int i = 0; i < ARRAY_SIZE; i++)
		{
			 stream >> buffer;
			 
			 if(buffer == 1) tab[i] = true;
			 else tab[i] = false;
		}

		file.close();
		return true;
	}
	else return false;
}

/**
*@name
*	saveArrayToFile
*@param
*	QString player - nazwa gracza
*	
*@return
*	true - gdy zapisano bez cudów
*	false w innym przypadku
*
*	Metoda odpowiadaj¹ca za zapis stanu flag do odpowiedniego 
*	pliku "nazwa_gracza.dat" z folderu ./users/flags
*/

bool FlagsContainer::saveArrayToFile(QString player)
{
	QString testbuf = "";
	QString filename = "./users/flags/" + player + ".dat";
	
	QFile file(filename);
	
	if ( file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream stream( &file );
		
		for(int i = 0; i < ARRAY_SIZE; i++)
			if(tab[i]) stream << "1" << endl;
			else stream << "0" << endl;

		file.close();
		
		return true;
	}
	else return false;
}

/**
*@name
*	getLenghtOfpath
*@param
*	void
*	
*@return
*	int - d³ugoœæ œcie¿ki z odblokowanych flag
*
*	Funkcja zwraca iloœæ krawêdzi w grafie, dziêki którym mo¿emy przejœæ
*	od pierwszej do ntej flagi, gdzie 1 <= n <= ARRAY_SIZE
*/

int FlagsContainer::getLenghtOfPath()
{
	for(int i = 0; i < ARRAY_SIZE; i++)
		if(!tab[i]) return i;
	
	return 16;
}

/**
*@name
*	getStateOfFlag
*@param
*	int level - któr¹ flagê nale¿y sprawdziæ
*	
*@return
*	true - gdy flaga ju¿ jest odblokowana i mo¿na robiæ na niej eventy
*	false - gdzie flaga jest zablokowana (enable = false)
*
*	Funkcja zwraca wartoœæ logiczn¹, czy flaga jest zablokowana czy te¿ nie
*/

bool FlagsContainer::getStateOfFlag(int lvl)
{
	lvl--;
	
	if(tab[lvl]) return true;
	else return false;
}

/**
*@name
*	printToString
*@param
*	void
*	
*@return
*	QString - zwraca ci¹g jedynek i zer w postaci stringa
*
*	Funkcja pomocniczam która zwraca stan kontenera
*/

QString FlagsContainer::printToString()
{
	QString a;
	
	for(int i = 0; i < ARRAY_SIZE; i++)
		if(tab[i]) a = a + "1 ";
		else a = a + "0 ";
		
	return a;
}