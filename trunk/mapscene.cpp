#include "mapscene.h"

/**
*@name
*	MapScene
*
*	Konstruktor tworzący scenę odpowiadający za mapę. 
*	Tworzy on pustą scenę z czarnym tłem. i ustawiający odpowiedni rysunek
*/

MapScene::MapScene(FlagsContainer *flags):
	QObject()
{
	this->scena = new QGraphicsScene();
	
	//flagi do flagi
		this->flags = flags;
	
	//czarne te³ko
		QColor black(0,0,0);
		QBrush brusz(black);
		
		this->scena->setBackgroundBrush(brusz);
	
	//dodanie mapy - tutaj jest dodana mgła wojny! 
		
		QString path = "./graphics/map/" + QString::number(flags->getLenghtOfPath() - 1) + ".png";
		
		QPixmap mapa(path);
		
		this->scena->addPixmap(mapa);
}

/**
*@name
*	getScena
*@param
*	void
*@return
*	QGraphicsScene* - wskaźnik do sceny
*
*	Getter zwracający wskaźnik do sceny
*/
	
QGraphicsScene* MapScene::getScena()
{
	return this->scena;
}

/**
*@name
*	addFlagToMap
*
*@param
*	int x - pozycja x
* 	int y - pozycja y
*	int lvl - 	za jaki level będzie odpowiadać dana flaga
*				to znaczy, że jakiego numeru sygnał ona wyemituje
*				po naciśnięciu tej flagi (który będzie odpowiadał jakiemuś poziomowi)
*	bool enable - czy flaga na początku ma być włączona, czy też wyłączona
*
*@return
*	void
*
*	Metoda ta umieszcza flagę na scenie, i od razu przypisuje jej numer poziomu
*	do którego będzie się ona odwoływać (parametr lvl). Także ona ustawia status flagi
*/

void MapScene::addFlagToMap(int x, int y, int lvl, bool enable)
{
	MapFlagButton *flaga = new MapFlagButton(x, y , lvl, enable);
	this->scena->addItem(flaga);
	
	QObject::connect(flaga, SIGNAL(sendFlagLevel(int)), this, SLOT(getFlagAndSendThemAway(int)));
}

/**
*@name
*	drawMap
*@param
*	void
*@return
*	void
*
*	Rysowanie mapy na scenie. TUTAJ DODAJEMY PRZYCISKI ZMIENIAMY CZCIONKI ETC!
*/

void MapScene::drawMap()
{
	//this->addGraphicsButton(300,300,3,true,"./graphics/primitives/2.png");
	
	//Świat dodawania
		this->addFlagToMap(646 ,502, LevelEngine::AdditionWorldLevel1, true);
		this->addFlagToMap(502, 441, LevelEngine::AdditionWorldLevel2, ((flags->getStateOfFlag(LevelEngine::AdditionWorldLevel2) == true) ? true : false));
		this->addFlagToMap(395, 522, LevelEngine::AdditionWorldLevel3, ((flags->getStateOfFlag(LevelEngine::AdditionWorldLevel3) == true) ? true : false));
		this->addFlagToMap(246, 492, LevelEngine::AdditionWorldLevel4, ((flags->getStateOfFlag(LevelEngine::AdditionWorldLevel4) == true) ? true : false));
		
	//Świat odejmowania
		this->addFlagToMap(136 ,513, LevelEngine::SubtractionWorldLevel1, ((flags->getStateOfFlag(LevelEngine::SubtractionWorldLevel1) == true) ? true : false));
		this->addFlagToMap(86, 500, LevelEngine::SubtractionWorldLevel2, ((flags->getStateOfFlag(LevelEngine::SubtractionWorldLevel2) == true) ? true : false));
		this->addFlagToMap(138, 451, LevelEngine::SubtractionWorldLevel3, ((flags->getStateOfFlag(LevelEngine::SubtractionWorldLevel3) == true) ? true : false));
		this->addFlagToMap(52, 397, LevelEngine::SubtractionWorldLevel4, ((flags->getStateOfFlag(LevelEngine::SubtractionWorldLevel4) == true) ? true : false));
		
	//Świat mnożenia
		this->addFlagToMap(103 ,332, LevelEngine::MultiplyWorldLevel1, ((flags->getStateOfFlag(LevelEngine::MultiplyWorldLevel1) == true) ? true : false));
		this->addFlagToMap(258 ,121, LevelEngine::MultiplyWorldLevel4, ((flags->getStateOfFlag(LevelEngine::MultiplyWorldLevel4) == true) ? true : false));
		this->addFlagToMap(213, 286, LevelEngine::MultiplyWorldLevel2, ((flags->getStateOfFlag(LevelEngine::MultiplyWorldLevel2) == true) ? true : false));
		this->addFlagToMap(163, 183, LevelEngine::MultiplyWorldLevel3, ((flags->getStateOfFlag(LevelEngine::MultiplyWorldLevel3) == true) ? true : false));
		
	//Świat dzielenia
		this->addFlagToMap(373, 132, LevelEngine::DivisionWorldLevel1, ((flags->getStateOfFlag(LevelEngine::DivisionWorldLevel1) == true) ? true : false));
		this->addFlagToMap(467, 187, LevelEngine::DivisionWorldLevel2, ((flags->getStateOfFlag(LevelEngine::DivisionWorldLevel2) == true) ? true : false));
		this->addFlagToMap(564, 230, LevelEngine::DivisionWorldLevel3, ((flags->getStateOfFlag(LevelEngine::DivisionWorldLevel3) == true) ? true : false));
		this->addFlagToMap(614 ,140, LevelEngine::DivisionWorldLevel4, ((flags->getStateOfFlag(LevelEngine::DivisionWorldLevel4) == true) ? true : false));
}

/**
*@name
*	getFlagAndSendThemAway
*@param
*	int level - wysyła sygnał, na jaki poziom mamy zmienić!
*@return
*	void
*
*	Wysyła sygnał do zmiany poziomu
*/

void MapScene::getFlagAndSendThemAway(int level)
{
	emit sendFlagAsGameLevel(level);
}
