#include "divisionlevel4.h"

DivisionLevel4::DivisionLevel4():
	DivisionEngine()
{
}

void DivisionLevel4::drawDivisionLevel()
{
	this->addText(70,100, 	tr("Jesteś taki fajny że aż ukończyłeś tę grę:\n\n Liczyłeś na starcie z różniczką lub całkołakiem?\n\n\n niestety! \n\nTakie zabawy tylko na studiach ;p \n \n Pozdro600"));
	
	
	
	this->addPicture(525, 115, "./graphics/lvl/2.png");
	this->addButton(470, 510, LevelEngine::Map, tr("Wróc do mapy"), "");
}