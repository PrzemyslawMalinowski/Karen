#include "abstractbutton.h"

AbstractButton::AbstractButton(int x, int y) :
	QObject(), QGraphicsPixmapItem()
{	
	//pozycja
		this->x = x;
		this->y = y;
	
	//wl�czenie przycisku
		this->enable = true;
	
	//pozwolenie na odbieranie event�w zas�aniania
	//przycisku
		this->setAcceptHoverEvents(true);
}

void AbstractButton::setEnabled(bool tru)
{
	this->enable = tru;
}