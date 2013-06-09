#include "graphicsbutton.h"

GraphicsButton::GraphicsButton(int x, int y, int number, bool match, const QString& path):
	AbstractButton(x, y)
{
	srand(time(NULL));
	
	this->number = number;
	
	//QGraphicsPixmapItem *tab[number]; // to jest standard C99, nie C++ ;p -Radzio
	//tab = new vector<QGraphicsitem>(number);
	this->tab = QVector<QGraphicsPixmapItem*>(number);
	
	this->isMatch = match;
	this->wasEvent = false;
	
	QPixmap graphic(path);
	this->setPos(x,y);
	int xI = 0, yI = 0;
	for(int i = 0; i < number; i++)
	{
		QGraphicsPixmapItem* item = new QGraphicsPixmapItem();
		
		//int xRand, yRand;
		
		//xRand = (rand() + rand()) % 50;
		//yRand = (rand() + rand()) % 50;
		
		tab[i] = item;
		tab[i]->setPixmap(graphic);
		tab[i]->setPos(xI, yI);
		tab[i]->setParentItem(this);
		yI+=15, xI+=10; if (number/2==i) xI+=40-i*10, yI=0;
	}
	
	QPixmap g("./graphics/primitives/t.png");
	this->setPixmap(g);
	this->setScale(0.9);
	this->show();
	
	for(int i = 0; i < number; i++)
		tab[i]->show();
}

void GraphicsButton::mousePressEvent(QGraphicsSceneMouseEvent * /*event*/)
{
	if(enable)
	{
		emit sendAnsferSignal(this->isMatch);
	}
}

void GraphicsButton::hoverEnterEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	if(enable)
	{
		this->setScale(1.);
		this->setPos(x-5,y-5);
	}
}

void GraphicsButton::hoverLeaveEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	if(enable)
	{
		this->setPos(x,y);
		this->setScale(0.9);
	}
}
