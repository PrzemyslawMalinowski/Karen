#include "abstractbutton.h"

AbstractButton::AbstractButton(int x, int y) :
	QObject(), QGraphicsPixmapItem()
{	
	//pozycja
		this->x = x;
		this->y = y;
	
	//wl¹czenie przycisku
		this->enable = true;
	
	//pozwolenie na odbieranie eventów zas³aniania
	//przycisku
		this->setAcceptHoverEvents(true);
}

void AbstractButton::setEnabled(bool tru)
{
	this->enable = tru;
}