#include "mapflagbutton.h"

MapFlagButton::MapFlagButton(int x, int y, int lvl, bool enable):
	QObject(), QGraphicsPixmapItem()
{
	
	//akceptowanie zdarzeń z najeżdżaniem myszą
		this->setAcceptsHoverEvents(true);
	
	//wczytywanie grafik
		this->hoverFlag = new QPixmap("./graphics/flags/1.png");
		this->unHoverFlag = new QPixmap("./graphics/flags/2.png");
		this->disabledFlag = new QPixmap("./graphics/flags/0v2.png");
	
	//ustawienie domyślnej
		if(enable == true)
			this->setPixmap(*this->unHoverFlag);
		else
			this->setPixmap(*this->disabledFlag);
	
	//this->setScale(0.75);
	
	//ustawianie pól obiektu
		this->level = lvl;
		this->setPos(x,y);
		this->enableFlag = enable;
}

void MapFlagButton::setFlagEnable(bool /*flag*/)
{
	if(this->enableFlag == true){
		this->enableFlag = false;
		return;
	}
	
	this->enableFlag = true;
}

bool MapFlagButton::getFlagEnable()
{
	return this->enableFlag;
}

/*
	EVENTS
*/

void MapFlagButton::mousePressEvent(QGraphicsSceneMouseEvent * /*event*/)
{
	if(this->enableFlag == true)
		emit sendFlagLevel(this->level);
}

void MapFlagButton::hoverEnterEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	if(this->enableFlag == true)
		this->setPixmap(*this->hoverFlag);
}

void MapFlagButton::hoverLeaveEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	if(this->enableFlag == true) 
		this->setPixmap(*this->unHoverFlag);
}
