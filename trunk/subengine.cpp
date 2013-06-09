#include "subengine.h"

/**
*@name
*	SubEngine
*
*	Ustawia on domyślnie tło mędrca!
*/

SubEngine::SubEngine():
	LevelEngine()
{	
	//dodanie mapy
		QPixmap uczony("./graphics/sage/uczony.png");
		
		this->scena->addPixmap(uczony);
}

