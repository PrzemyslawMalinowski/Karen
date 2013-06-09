#include "divisionengine.h"

/**
*@name
*	DivisionEngine
*
*	Ustawia on domyślnie tło mędrca!
*/

DivisionEngine::DivisionEngine():
	LevelEngine()
{	
	//dodanie mapy
		QPixmap uczony("./graphics/sage/uczony.png");
		
		this->scena->addPixmap(uczony);
}
