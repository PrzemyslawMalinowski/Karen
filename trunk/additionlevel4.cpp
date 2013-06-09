﻿#include "additionlevel4.h"

/**
*@name
*	AdditionLevel4
*
*	Konstruktor ten zmienia tapetę na widok rozgrywki:)
*/
AdditionLevel4::AdditionLevel4():
	AdditionEngine()
{
	QPixmap uczony("./graphics/lvl/lvl");	
	this->scena->addPixmap(uczony);
}

/**
*@name
*	drawAdditionLevel
*@param
*	void
*@return
*	void
*
*	Rysowanie poziomu. Należy zawsze, ale to zawsze pamiętać, iż 
*	TO ODPOWIADA TYLKO I WYŁĄCZNIE za jego rysowanie
*/

void AdditionLevel4::drawAdditionLevel()
{
	//czyszczenie poprzedniej wersji levelu
		this->clear();
		
	//rysowanie nowej
		this->draw();
}

/**
*@name
*	clear()
*@param
*	void
*@return
*	void
*
*	Czyści zawartość sceny
*
*/

void AdditionLevel4::clear()
{
	this->scena->clear();
	
	QPixmap uczony("./graphics/lvl/lvl");	
	this->scena->addPixmap(uczony);
}

/**
*@name
*	addGraphicsButton
*@param
*	int x, y - umiejscownie
*	int number - ilość obrazków na scenia
*	bool match - czy to jest dobra odpowiedź
*	QString path - ścieżka do prymitywa
*
*	Jest to nadpisany odpowiednik z silnika pod kątem tego levela
*/

void AdditionLevel4::addGraphicsButton(int x, int y, int number, bool match, const QString& path)
{
	GraphicsButton *przycisk = new GraphicsButton(x, y , number, match, path);
	this->scena->addItem(przycisk);
	
	QObject::connect(przycisk, SIGNAL(sendAnsferSignal(bool)), this, SLOT(sendAnsferSlot(bool)));
}

/**
*@name
*	sendAnsferSlot
*@param 
*	bool match
*@return 
*	void
*@type
*	slot
*
*	Powiadamia gracza o sukcesie w wyborze odpowiedniej odpowiedzi
*	oraz emituje sygnał, czy odpowiedź jest ok, czy też nie
*/

void AdditionLevel4::sendAnsferSlot(bool match)
{
		if(match)
		{
			QMessageBox msg;
			msg.setWindowTitle("Informacja");
			msg.setText(tr("Brawo, poprawnie rozwiązałeś zagadkę :)"));
			msg.exec();
		}
		else
		{
			QMessageBox msg;
			msg.setWindowTitle("Informacja");
			msg.setText(tr("Ojej, chyba Tobie nie poszło :("));
			msg.exec();
		}
		
		emit isMatchedSignal(match);
}

/**
*@name
*	randomizeNotLike
*@param
*	int liczba - jaką nie chcemy wylosować liczbą
*@return
*	int - zwraca liczbą różną od liczba z prezedziału 1 - 10
*
*	Podprogram ten soluje liczbę z przedziału dyskretnego 1 - 10
*	różną od liczba
*/

int AdditionLevel4::randomizeNotLike(int liczba)
{
	bool prawda = true;
	int liczba2 = 0;
	
	while(prawda)
	{
		liczba2 = (rand() % 10) + 1;
		
		if(liczba2 != liczba)
			prawda = false;
	}
	
	return liczba2;
}

/**
*@name
*	draw
*@param
*	void
*@return
*	void
*	
*	Rysuje poszczególną zagadkę - funkcja ta jest potrzebna do "multilevela"
*
*/

void AdditionLevel4::draw()
{
	QString prymityw = "./graphics/primitives/";
	
	int liczba = (rand() % 10) + 1; 
	int odp1, odp2, odp3;
	
	unsigned short int primitive = (rand() % 10) + 1;
	
	//dodanie tekstu
	
		this->setTextWidthSeparator(600.0);
		this->setFont("AquilineTwo", 54);
		this->setFontColor(0,0,0,255);
		this->addText(230,-40, 	tr("Dodawanie"));
	
	//ustalenie prymitywa
		prymityw += QString::number(primitive) + ".png";
	
	//czyszczenie podłoża i ustalanie randomizacji
		srand(time(NULL));
	
	//dodawanie grafików
		this->addPicture(237, 219, "./graphics/lvl/1");
		this->addPicture(495, 219, "./graphics/lvl/0");
		
	//wylosowanie odpowiedzi
		bool prawda = true;
		
		while(prawda)
		{
			odp1 = rand() % 10 + 1;
			
			if(odp1 <= liczba)
				prawda = false;
		}
	
	//losowanie błędnych odpowiedzi
	
		odp2 = this->randomizeNotLike(odp1);
		odp3 = this->randomizeNotLike(odp1);
		
	//QMessageBox a;
	//a.setText(QString::number(liczba) + " " + QString::number(odp1) + " " + QString::number(odp2) + " " + QString::number(odp3));
	//a.exec();
	
	//rysowanie podpowiedzi
		int randr;
		
		randr = (rand() % 3);
		
		switch(randr)
		{
			//odpowiedź po lewej części lewej strony i po prawej
			case 0:
			{
			
				for(int i = 0; i < liczba; i++)
					this->addPicture(597 + i * 10, 175 + i * 10,prymityw);
					
				for(int i = 0; i < (liczba - odp1); i++)
					this->addPicture(85 + i * 10, 187 + i * 10,prymityw);
					
				this->addPicture(343, 184, "./graphics/lvl/qm.png");	
					
			} break;
			
			//odpowiedź po prawe części lewej strony i po prawej
			case 1 :
			{
			
				for(int i = 0; i < liczba; i++)
					this->addPicture(597 + i * 10, 175 + i * 10,prymityw);
					
				for(int i = 0; i < (liczba - odp1); i++)
					this->addPicture(342 + i * 10, 174 + i * 10,prymityw);
					
				this->addPicture(90, 184, "./graphics/lvl/qm.png");	
					
			} break;
			
			//obie po levej
			case 2 :
			{
			
				this->addPicture(597, 184, "./graphics/lvl/qm.png");	
			
				for(int i = 0; i < (liczba - odp1); i++)
					this->addPicture(342 + i * 10, 174 + i * 10,prymityw);
					
				for(int i = 0; i < odp1; i++)
					this->addPicture(85 + i * 10, 187 + i * 10,prymityw);
					
			} break;
		}
			
			
	//rysowanie i obsługa buttonów
		int randr2 = rand() % 3;
		
		switch(randr2)
		{
			case 0: 
			{
				this->addGraphicsButton(115, 405, (randr != 2) ? odp1 : liczba , true, prymityw);
				this->addGraphicsButton(331, 405, odp2, false, prymityw);
				this->addGraphicsButton(541, 405, odp3, false, prymityw);
			}
			break;
			case 1:
			{
				this->addGraphicsButton(115, 405, odp2, false, prymityw);
				this->addGraphicsButton(331, 405, (randr != 2) ? odp1 : liczba, true, prymityw);
				this->addGraphicsButton(541, 405, odp3, false, prymityw);
			}
			break;
			case 2:
			{
				this->addGraphicsButton(115, 405, odp3, false, prymityw);
				this->addGraphicsButton(331, 405, odp2, false, prymityw);
				this->addGraphicsButton(541, 405, (randr != 2) ? odp1 : liczba, true, prymityw);
			}
			break;
		}
		
	this->addButton(620, 510, LevelEngine::Map, tr("Wróc do mapy"), "");
}
