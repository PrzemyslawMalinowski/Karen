#include "levelengine.h"

/**
*@name
*	LevelEngine
*
*	Konstruktor tworzący pustą scenę, kolorujący ją na czarno 
*	i ustawiający czcionkę
*/

LevelEngine::LevelEngine():
	QObject()
{
	this->scena = new QGraphicsScene();
		
		//ustawianie czcionków
		
			fontColor = new QColor(255,255,255,240); //domyślnie ma być białe
		
			this->font = new QFont("fantasy");
			this->font->setStyleHint(QFont::Decorative);
			
			textWidth = 300.0;
		
		//czarne tełko
			QColor black(0,0,0);
			QBrush brusz(black);
			
			this->scena->setBackgroundBrush(brusz);
}

/**
*@name
*	getScena
*@params
*	void
*@return
*	QGraphicsScene* - wskaźnik do sceny
*
*	Metoda zwraca scenę danego poziomu. (Używamy tej funkcji, gdy chcemy wyświetlić scenę
*	w odpowiedniej formatce)
*/

QGraphicsScene* LevelEngine::getScena()
{
	return this->scena;
}

/**
*@name
*	addText
*@params
*	int x - pozycja x
*	int y - pozycja y
*	QString text - co chemy wypisać na scenie
*@return
*	void
*
*	Metoda ta dodaje do sceny napis. Jeżeli trzeci parametr
*	będzie na przykład: "Jedwabisty" to to zostanie umieszczone na scenie.
*
*/

void LevelEngine::addText(int x, int y, const QString& text)
{
	QGraphicsTextItem *tmp = this->scena->addText(text, *font);
	
	//zmiana koloru na bioly
		tmp->setDefaultTextColor(*fontColor);
		
	//zmiana dlugosci
		tmp->setTextWidth(textWidth);
		
	//zmiana pozycji w scenie
		tmp->setPos(x, y);
	
}

/**
*@name
*	addPicture
*@params
*	int x - pozycja x
*	int y - pozycja y
*	QString text - ścieżka do pliku
*@return
*	void
*
*	Metoda ta dodaje do sceny rysunek.
*
*/

void LevelEngine::addPicture(int x, int y, const QString& path)
{
	//QColor bialy(255,255,255,240);
		QGraphicsPixmapItem *tmp = this->scena->addPixmap(path);
		
	//zmiana pozycji w scenie
		tmp->setPos(x, y);
	
}

/**
*@name
*	addText
*@params
*	int x - pozycja x
*	int y - pozycja y
*	int lvl - level, do którego przycisk ma posyłać po naciśnięciu
*	QString text - co chemy wypisać na scenie
*@return
*	void
*
*	Metoda ta dodaje przycisk do sceny. lvl ma określać, co ma ten przycis emitować za sygnał.
*/

void LevelEngine::addButton(int x, int y, int lvl, const QString& text, const QString& path)
{
	//tworzenie nowego przycisku oraz dodanie go do sceny
		GraphicsButtonFromPicture *button = new GraphicsButtonFromPicture(x, y, lvl, text, path);
		this->scena->addItem(button);
		
	//ustawienie nasłuchiwania na ten obiekt
		QObject::connect(button, SIGNAL(clickedSignal(int)), this, SLOT(buttonClicked(int)));
}

/**
*@name
*	setFont
*@param
*	QString name - 	podajemy nazwę czcionki lub rodziny - więcej o rodzinach w dokumentacji
*					QT
*	int size - rozmiar czcionki w pixelach
*
*	Zmienia czcionkę oraz jej rozmiar. Tą funkcję używamy PRZED	wypisaniem tekstu, który chcemy, żeby był w tej czcionce.
*
*	TIPS & TRICKS:
*		*	Dopóki nie wywołamy tej funkcji z parametrem ("normal", jakaśLiczba), czcionka ta będzie obowiązywać do czasu
*			dopóki obiekt z levelem nie będzie zniszczony;
*		*	Wezwij tą funkcję z parametrem (NULL, liczba) lub ("", liczba) by tylko zwiększyć czcionkę
*/

void LevelEngine::setFont(const QString& name, int size = 12)
{
			if(name != "" || name != NULL){
				this->font->setFamily(name);
				this->font->setStyleHint(QFont::Decorative);
			}
			
			if(name == "normal"){
				this->font->setFamily("fantasy");
				this->font->setStyleHint(QFont::Decorative);
			}
			
			this->font->setPointSize(size);
}

/**
*@name
*	setFontColor
*@param
*	int x, y, z - kolor RGB 
*	int alpha - ustawienie przezroczystości, zakres:
*	0 - 255 gdzie 255 to całkowita nieprzezroczystość
*
*	Zmienia kolor czcionki
*/

void LevelEngine::setFontColor(int x, int y, int z, int alpha = 255)
{
	fontColor->setRgb(x,y,z,alpha);
}

/**
*@name
*	setTextWidthSeparator
*@param
*	number - odległość, która będzie odpowiedzialna za dzielenie
*			 tekstu na ekranie
*@return
*	void
*
*	Metoda ta ustawia separator, który będzie dzielił na ekranie. 
*	
*	Przykład bez separatora:
*
*		tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst tekst
*
*	Przykład z separatorem:
*	
*		tekst tekst tekst tekst tekst tekst tekst tekst
*		tekst tekst tekst tekst tekst tekst tekst
*
*/

void LevelEngine::setTextWidthSeparator(qreal number)
{
	this->textWidth = number;
}

/**
*@name
*	buttonClicked
*@type
*	signal
*@param
*	int setLevel - numer levela, do którego chcemy dojść
*@return
*	void
*
*	Emituje sygnał do zmiany levelu
*/

void LevelEngine::buttonClicked(int setLevel)
{
	//emituj sygnał do obsłużenia
		emit setLevelSignal(setLevel);	
}

/**
*@name
*	addGraphicsButton
*@return 
*	void
*@param
*	int x, y - umiejscowienie na scenie
*	int number - liczba obiektów na przycisku
*	bool match - czy to jest dobra odpowiedź
*	QString name - ścieżka do prymitywa
*
*
*	Tworzy graficzny przycisk do bossa :D
*/

void LevelEngine::addGraphicsButton(int x, int y, int number, bool match, const QString& name)
{
	GraphicsButton *przycisk = new GraphicsButton(x, y , number, match, name);
	this->scena->addItem(przycisk);
}