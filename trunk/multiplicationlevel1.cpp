#include "multiplicationlevel1.h"

MultiplicationLevel1::MultiplicationLevel1():
    MultiplicationEngine()
{
}

void MultiplicationLevel1::drawMultiplicationLevel()
{

    this->addText(70,100, 	tr("Witaj!\n") +
                    tr("Wchodząc do lasu zauważasz jak wielka jest ilość drzew która Cię właśnie otoczyła.\n\n ") +
                    tr("Nie sposób zgadnąć ile czasu poświęcilbyśmy gdyby liczyć je wszystkie dodając każde osobno.\n\n ")+
					tr("Dlatego właśnie musisz nauczyć się sztuki mnożenia!")
					);

    this->addButton(470, 510, LevelEngine::Map, tr("Wróc'do mapy"), "");

}
