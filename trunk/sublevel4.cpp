#include "sublevel4.h"


/**
*@name
*	SubLevel4
*
*	Konstruktor ten zmienia tapetę na widok rozgrywki:)
*/
SubLevel4::SubLevel4():
	SubEngine()
{
	QPixmap uczony("./graphics/lvl/lvl");	
	this->scena->addPixmap(uczony);
}

void SubLevel4::drawSubLevel()
{
	//czyszczenie poprzedniej wersji levelu
		this->clear();
		
	//rysowanie nowej
		this->draw();
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

void SubLevel4::draw()
{
	//ustawienia czcionki dla tego lvl
	this->setTextWidthSeparator(600.0);
	this->setFont("AquilineTwo", 54);
	this->setFontColor(0,0,0,255);

	srand(time(NULL));
	
	//grafiki stale i napis
	this->addPicture(230, 200, "./graphics/lvl/2.png");
	this->addPicture(490, 200, "./graphics/lvl/0.png");
	this->addPicture(620, 180, "./graphics/lvl/qm.png");
	this->setFont("", 54);
	this->addText(240,-40, 	tr("Odejmowanie"));
	
	//ustalanie prymitywa
	QString prymityw = "./graphics/primitives/";
	unsigned short int primitive = (rand() % 10) + 1;
	prymityw += QString::number(primitive) + ".png";
	
	//ustalanie odpowiedzi i podpowiedzi
	int liczba = (rand() % 5) + 1;
	int odejmna = 0;
	while (odejmna < liczba) odejmna = (rand () % 10 ) + 1;
	int odejmnik = odejmna - liczba;
	int x = 0, y = 0;
	 
	int odp1, odp2, odp3;
	// rysowanie odejmnej i odejmnika
		for (int i =0; i<odejmna; ++i) 
		{this->addPicture(75+x, 200+y,prymityw); y+=15, x+=10; if (odejmna/2==i) x+=40-i*10, y=0;} x=0,y=0;
		for (int i =0; i<odejmnik; ++i)
		{this->addPicture(350+x, 200+y,prymityw); y+=15, x+=10; if (odejmnik/2==i) x+=40-i*10, y=0;} x=0,y=0;
	
	//losowanie błędnych odpowiedzi
		odp1 = liczba;
		odp2 = this->randomizeNotLike(liczba);
		odp3 = this->randomizeNotLike(liczba);
	
	//rysowanie i obsługa buttonów
		int randr;
		randr = rand() % 3;
		
		switch(randr)
		{
			case 0: 
			{
				this->addGraphicsButton(115, 405, odp1, true, prymityw);
				this->addGraphicsButton(331, 405, odp2, false, prymityw);
				this->addGraphicsButton(541, 405, odp3, false, prymityw);
			}
			break;
			case 1:
			{
				this->addGraphicsButton(115, 405, odp2, false, prymityw);
				this->addGraphicsButton(331, 405, odp1, true, prymityw);
				this->addGraphicsButton(541, 405, odp3, false, prymityw);
			}
			break;
			case 2:
			{
				this->addGraphicsButton(115, 405, odp3, false, prymityw);
				this->addGraphicsButton(331, 405, odp2, false, prymityw);
				this->addGraphicsButton(541, 405, odp1, true, prymityw);
			}
			break;
		}



	this->addButton(620, 510, LevelEngine::Map, tr("Wróc do mapy"), "");
	this->setTextWidthSeparator(300.0);
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


void SubLevel4::clear()
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

void SubLevel4::addGraphicsButton(int x, int y, int number, bool match, const QString& path)
{
	GraphicsButton *przycisk = new GraphicsButton(x, y , number, match, path);
	this->scena->addItem(przycisk);
	
	QObject::connect(przycisk, SIGNAL(sendAnsferSignal(bool)), this, SLOT(sendAnsferSlot(bool)));
}
/**
*/

int SubLevel4::randomizeNotLike(int liczba)
{
	int liczba2 = 0;
	
	while(true)
	{
		liczba2 = (rand() % 8) + 1;
		if(liczba2 != liczba) break;
	}
	
	return liczba2;
}


void SubLevel4::sendAnsferSlot(bool match)
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
