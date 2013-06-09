#include "additionlevel3.h"

AdditionLevel3::AdditionLevel3():
	AdditionEngine()
{
}

void AdditionLevel3::drawAdditionLevel()
{

	this->addText(60,120, 	tr("Dla dodawania zachodzą następujące własności:\n"));
	
	this->addPicture(90, 170, "./graphics/primitives/4.png");
	this->addPicture(140, 170, "./graphics/primitives/4.png");
	
	/**/this->addPicture(180, 175, "./graphics/lvl/1s.png");
	
	this->addPicture(220, 170, "./graphics/primitives/4.png");
	
	/**/this->addPicture(170, 220, "./graphics/lvl/0s.png");
	
	this->addPicture(90, 260, "./graphics/primitives/4.png");
	this->addPicture(180, 260, "./graphics/primitives/4.png");
	/**/this->addPicture(140, 265, "./graphics/lvl/1s.png");
	
	this->addPicture(240, 260, "./graphics/primitives/4.png");
	
	this->addText(60,320, 	tr("To inaczej znaczy, że po prostu zamiana kolejności dodawania nie ma znaczenia. Inną ważną rzeczą jest:"));
	
	this->addPicture(90, 400, "./graphics/primitives/6.png");
	
	/**/this->addPicture(140, 420, "./graphics/lvl/1s.png");
	/**/this->addPicture(240, 420, "./graphics/lvl/0s.png");
	
	this->addPicture(300, 400, "./graphics/primitives/6.png");
	
	this->addButton(480, 510, LevelEngine::Map, tr("Wróc do mapy"), "");
}
