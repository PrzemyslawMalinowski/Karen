#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
*@name 
*	MainWindow
*@param 
*	QWidget *parent
*
*	Konstruktor tworzący główne okno gry
*	tworzy on obiekt głównego z pliku generującego
*	ustawia on gracza, wczytuje z pliku stan flag
* 	i ustawia okno. Następnie zmienia on defaultowo na mapę
*/

MainWindow::MainWindow(QString player, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	//ustawienie szablonu
		ui->setupUi(this);
	
	//wczytywanie playera
		this->user = player;
		
	//tworzenie struktury flag
		kontenerFlag = new FlagsContainer();
		kontenerFlag->readArrayFromFile(this->user);

	//ustawienie opcji okna
		this->setWindowTitle("Karen");
		this->resize(860,660);
		
	//uruchomienie
		this->run();
}

/**
*
*
*
*
*
*
*/

void MainWindow::run()
{	
	this->setScene(LevelEngine::Map);
}

/**
*@name
*	unlockWorld
*@param
*	bool match - czy poprawna była odpowiedź
*@return
*	void
*
*	Odblokowywuje nowe światy
*/

void MainWindow::unlockWorld(bool match)
{
	if(match)
	{
		if(!kontenerFlag->getStateOfFlag(LevelEngine::SubtractionWorldLevel1))
		{
			kontenerFlag->unlockLevel(LevelEngine::SubtractionWorldLevel1);
			//return;
		}
		else if(!kontenerFlag->getStateOfFlag(LevelEngine::MultiplyWorldLevel1))
		{
			kontenerFlag->unlockLevel(LevelEngine::MultiplyWorldLevel1);
			//return;
		}
		else if(!kontenerFlag->getStateOfFlag(LevelEngine::DivisionWorldLevel1))
		{
			kontenerFlag->unlockLevel(LevelEngine::DivisionWorldLevel1);
			//return;
		}
	}
	
	this->setScene(LevelEngine::Map);
}

/**
*@name
*	~MainWindow
*
*	Usuwa on wszystkie obiekty
*/

MainWindow::~MainWindow()
{
    delete ui;
}

/**
*@name
*	setScene
*@type
*	slot
*@param
*	int lvl - na jaki level chcemu zmienić
*@return
*	void
*
*	Jest to slot, który w connect'cie zmienia levele
*	i wyświetla go na graphicsView. 
*
*	Jak to wygląda:
*	w switchu mamy wartości od 0 - 16:
*		0 - główna mapa,
*		reszta to levele, tyle że pierwsze cztery to świat dodawania, kolejne cztery odejmowania, i analogicznie
*		mnożenia i dzielenia
*		
*		SCHEMAT TWORZENIA LVL:
*
*		case nr_levelu : {	//zamiast numeru LVL można sie posłużyć stałymi z klasy LevelEngine
*							//i raczej zalecam, zeby tak robić
*
*			KlasaObsługującaTworzenieSceny nazwaLevelu = new KlasaObsługującaTworzenieSceny(kontenerFlag);
*										//kontener flag odpowiada za to, jakie flagi już odwiedził grasz
*
*			a->rysujElementyNaScenie(); //będzie to raczej funkcja drawMap() albo draw*Level()
*										//ta funkcja rysuje elementy na scenie, i dzięki dziedziczeniu z klasy LevelEngine
*										//można w tej funkcji dodawać oraz pozycjonować elementy na scenie.
*										//Dlatego ta funkcja MUSI być tutaj bo ona odwpowiada za umieszczenie elementów
*										//na tej scenie. gdyby jej tu nie było, to scena byłaby tutaj pusta, czyli nie byloby
*										//ani grafik ani przycisków
*			
*			this->ui->graphicsView->setScene(nazwaLevelu->getScena()); 	//do widgeta obsługującego wyświetlanie sceny "wsadzam"
*																		//odpowiednią scenę, która ma być pokazana
*																		//inaczej mówiąc graphicsView jest jakby "ramką" w obrazie
*																		//a zwracana scena przez funkcję getScena() jest "obrazem"
*																		//który nie jest widoczne bez umieszczenia jej w ramce
*
*			this->ui->graphicsView->show();	//ta funkcja mówi ramce, że ma wyświetlić zawartość sceny na ekran
*
*			QObject::connect(mapa, SIGNAL(sendFlagAsGameLevel(int)), this, SLOT(setScene(int))); //natomiast ta funkcja odpowiada za zmianę poziomu
*																								//czy też za powrót do mapy
*
*			(*) kontenerFlag->unlockLevel(LevelEngine::AdditionWorldLevelN);	//to obsługuje, jaki level N chcemy odblokować po przejściu tego levela
*
*			kontenerFlag->saveArrayToFile(player);							//za każdym razem zapisujemy stan gry
*
*			//WSZYSTKIE POWYŻSZE SKŁADNIKI KTÓRE NIE MAJĄ (*) MUSZĄ BYĆ TUTAJ WPISANE, żeby program miał sens i oczywiście działał
*		} break;
*/

void MainWindow::setScene(int lvl)
{
	switch(lvl){
	
		/*
				MAPA
		*/
		
		case LevelEngine::Map :{
		
		/*
			QMessageBox a;
			QString b = kontenerFlag->printToString();				
			a.setText(b);
			a.exec();
		*/
		
			//dodanie mapy i jej wyświetlenie łącznie z flagami
				MapScene *mapa = new MapScene(kontenerFlag);
				mapa->drawMap();

			this->ui->graphicsView->setScene(mapa->getScena());
			this->ui->graphicsView->show();
			
			QObject::connect(mapa, SIGNAL(sendFlagAsGameLevel(int)), this, SLOT(setScene(int)));
			kontenerFlag->saveArrayToFile(user);
		} break;
		
		/*
			ŚWIAT DODAWANIA: LEVEL 1
		*/
		
		case LevelEngine::AdditionWorldLevel1 : {
		
			//stwórz level 
				AdditionLevel1 *game = new AdditionLevel1();
				game->drawAdditionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::AdditionWorldLevel2);
			kontenerFlag->saveArrayToFile(user);
			
		} break;
		
		/*
			ŚWIAT DODAWANIA: LEVEL 2
		*/
		
		case LevelEngine::AdditionWorldLevel2 : {
		
			//stwórz level 
				AdditionLevel2 *game = new AdditionLevel2();
				game->drawAdditionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::AdditionWorldLevel3);
			kontenerFlag->saveArrayToFile(user);
			
		} break;
		
		/*
			ŚWIAT DODAWANIA: LEVEL 3
		*/
		
		case LevelEngine::AdditionWorldLevel3 : {
		
			//stwórz level 
				AdditionLevel3 *game = new AdditionLevel3();
				game->drawAdditionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			kontenerFlag->unlockLevel(LevelEngine::AdditionWorldLevel4);
			
		} break;
		
		/*
			ŚWIAT DODAWANIA: LEVEL 4 BOSS
		*/
		
		case LevelEngine::AdditionWorldLevel4 : {
			
			//stwórz level 
				AdditionLevel4 *game = new AdditionLevel4();
				game->drawAdditionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			QObject::connect(game, SIGNAL(isMatchedSignal(bool)), this, SLOT(unlockWorld(bool)));
			
			kontenerFlag->saveArrayToFile(user);
			
		} break;

		/*
			ŚWIAT ODEJMOWANIA: LEVEL 1 (5kawalek mapy)
		*/
		
		case LevelEngine::SubtractionWorldLevel1: {
		
			//stwórz level 
			SubLevel1 *game = new SubLevel1();
			game->drawSubLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::SubtractionWorldLevel2);
			kontenerFlag->saveArrayToFile(user);
					
			
		} break;
		
		
		/*
			ŚWIAT ODEJMOWANIA: LEVEL 2 (6kawalek mapy)
		*/
		
		case LevelEngine::SubtractionWorldLevel2: {
		
			//stwórz level 
			SubLevel2 *game = new SubLevel2();
			game->drawSubLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::SubtractionWorldLevel3);
			kontenerFlag->saveArrayToFile(user);		
			
			
		} break;
		
		
		/*
			ŚWIAT ODEJMOWANIA: LEVEL 3 (7kawalek mapy)
		*/
		
		case LevelEngine::SubtractionWorldLevel3: {
		
			//stwórz level 
			SubLevel3 *game = new SubLevel3();
			game->drawSubLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			kontenerFlag->unlockLevel(LevelEngine::SubtractionWorldLevel4);
			kontenerFlag->saveArrayToFile(user);
					
			
			
		} break;
		
		
		
		/*
			ŚWIAT ODEJMOWANIA: LEVEL 4 BOSS (8kawalek mapy)
		*/
		
		case LevelEngine::SubtractionWorldLevel4: {
		
			//stwórz level 
			SubLevel4 *game = new SubLevel4();
			game->drawSubLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			QObject::connect(game, SIGNAL(isMatchedSignal(bool)), this, SLOT(unlockWorld(bool)));

            //kontenerFlag->unlockLevel(LevelEngine::MultiplyWorldLevel1);
			kontenerFlag->saveArrayToFile(user);
					
			
			
		} break;


        /*
            ŚWIAT MNOŻENIA: LEVEL 1 (9kawalek mapy)
        */

        case LevelEngine::MultiplyWorldLevel1: {

            //stwórz level
            MultiplicationLevel1 *game = new MultiplicationLevel1();
            game->drawMultiplicationLevel();

            this->ui->graphicsView->setScene(game->getScena());
            this->ui->graphicsView->show();


            QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));

            kontenerFlag->unlockLevel(LevelEngine::MultiplyWorldLevel2);
            kontenerFlag->saveArrayToFile(user);


        } break;


        /*
            ŚWIAT MNOŻENIA: LEVEL 2 (10kawalek mapy)
        */

        case LevelEngine::MultiplyWorldLevel2: {

            //stwórz level
            MultiplicationLevel2 *game = new MultiplicationLevel2();
            game->drawMultiplicationLevel();

            this->ui->graphicsView->setScene(game->getScena());
            this->ui->graphicsView->show();


            QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));

            kontenerFlag->unlockLevel(LevelEngine::MultiplyWorldLevel3);
            kontenerFlag->saveArrayToFile(user);


        } break;


        /*
            ŚWIAT MNOŻENIA: LEVEL 3 (11kawalek mapy)
        */

        case LevelEngine::MultiplyWorldLevel3: {

            //stwórz level
            MultiplicationLevel3 *game = new MultiplicationLevel3();
            game->drawMultiplicationLevel();

            this->ui->graphicsView->setScene(game->getScena());
            this->ui->graphicsView->show();


            QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
            kontenerFlag->unlockLevel(LevelEngine::MultiplyWorldLevel4);
            kontenerFlag->saveArrayToFile(user);



        } break;



        /*
            ŚWIAT MNOŻENIA: LEVEL 4 BOSS (12kawalek mapy)
        */

        case LevelEngine::MultiplyWorldLevel4: {

            //stwórz level
            MultiplicationLevel4 *game = new MultiplicationLevel4();
            game->drawMultiplicationLevel();

            this->ui->graphicsView->setScene(game->getScena());
            this->ui->graphicsView->show();


            QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
            QObject::connect(game, SIGNAL(isMatchedSignal(bool)), this, SLOT(unlockWorld(bool)));

            //kontenerFlag->unlockLevel(LevelEngine::DivisionWorldLevel1);
            kontenerFlag->saveArrayToFile(user);



        } break;



		/*
            ŚWIAT DZIELENIA: LEVEL 1 (13kawalek mapy)
		*/
		
		case LevelEngine::DivisionWorldLevel1: {
		
			//stwórz level 
			DivisionLevel1 *game = new DivisionLevel1();
			game->drawDivisionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::DivisionWorldLevel2);
			kontenerFlag->saveArrayToFile(user);
					
			
		} break;
		
		
		/*
            ŚWIAT DZIELENIA: LEVEL 2 (14kawalek mapy)
		*/
		
		case LevelEngine::DivisionWorldLevel2: {
		
			//stwórz level 
			DivisionLevel2 *game = new DivisionLevel2();
			game->drawDivisionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			
			kontenerFlag->unlockLevel(LevelEngine::DivisionWorldLevel3);
			kontenerFlag->saveArrayToFile(user);		
			
			
		} break;
		
		
		/*
            ŚWIAT DZIELENIA: LEVEL 3 (15kawalek mapy)
		*/
		
		case LevelEngine::DivisionWorldLevel3: {
		
			//stwórz level 
			DivisionLevel3 *game = new DivisionLevel3();
			game->drawDivisionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			kontenerFlag->unlockLevel(LevelEngine::DivisionWorldLevel4);
			kontenerFlag->saveArrayToFile(user);
					
			
			
		} break;
		
		
		
		/*
            ŚWIAT DZIELENIA: LEVEL 4 BOSS (16kawalek mapy)
		*/
		
		case LevelEngine::DivisionWorldLevel4: {
		
			//stwórz level 
			DivisionLevel4 *game = new DivisionLevel4();
			game->drawDivisionLevel();
			
			this->ui->graphicsView->setScene(game->getScena());
			this->ui->graphicsView->show();
			
			
			QObject::connect(game, SIGNAL(setLevelSignal(int)), this, SLOT(setScene(int)));
			//QObject::connect(game, SIGNAL(isMatchedSignal(bool)), this, SLOT(unlockWorld(bool)));

			kontenerFlag->saveArrayToFile(user);
					
			
			
		} break;


		
	}
}
