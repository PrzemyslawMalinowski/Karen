#include "multiplicationlevel3.h"

MultiplicationLevel3::MultiplicationLevel3():
    MultiplicationEngine()
{
}

void MultiplicationLevel3::drawMultiplicationLevel()
{

    this->addText(70,100, 	tr("Kilka przykladow mnożenia:\n"));
    // 2 * 1 = 2
    this->addPicture(65, 130, "./graphics/primitives/2.png");
    this->addPicture(85, 140, "./graphics/primitives/2.png");
    /**/this->addPicture(145, 130, "./graphics/lvl/3s.png");
    this->addPicture(195, 130, "./graphics/primitives/2.png");
    /**/this->addPicture(250, 140, "./graphics/lvl/0s.png");
    this->addPicture(305, 130, "./graphics/primitives/2.png");
    this->addPicture(325, 140, "./graphics/primitives/2.png");

    // 4 * 2 = 8
    this->addPicture(55, 210, "./graphics/primitives/5.png");
    this->addPicture(85, 210, "./graphics/primitives/5.png");
    this->addPicture(100, 225, "./graphics/primitives/5.png");
    this->addPicture(70, 225, "./graphics/primitives/5.png");

    /**/this->addPicture(145, 215, "./graphics/lvl/3s.png");
    this->addPicture(190, 215, "./graphics/primitives/5.png");
    this->addPicture(210, 225, "./graphics/primitives/5.png");
    /**/this->addPicture(250, 215, "./graphics/lvl/0s.png");
    this->addPicture(285, 215, "./graphics/primitives/5.png");
    this->addPicture(305, 215, "./graphics/primitives/5.png");
    this->addPicture(325, 215, "./graphics/primitives/5.png");
    this->addPicture(345, 215, "./graphics/primitives/5.png");
    this->addPicture(285, 220, "./graphics/primitives/5.png");
    this->addPicture(305, 220, "./graphics/primitives/5.png");
    this->addPicture(325, 220, "./graphics/primitives/5.png");
    this->addPicture(345, 220, "./graphics/primitives/5.png");

    //3 * 0 = 0
    this->addPicture(55, 300, "./graphics/primitives/7.png");
    this->addPicture(75, 310, "./graphics/primitives/7.png");
    this->addPicture(90, 320, "./graphics/primitives/7.png");
    /**/this->addPicture(145, 310, "./graphics/lvl/3s.png");
    /**/this->addPicture(270, 310, "./graphics/lvl/0s.png");

    // 6 * 1 = 6
    this->addPicture(55, 390, "./graphics/primitives/8.png");
    this->addPicture(85, 390, "./graphics/primitives/8.png");
    this->addPicture(70, 405, "./graphics/primitives/8.png");
    this->addPicture(100, 405, "./graphics/primitives/8.png");
    this->addPicture(115, 420, "./graphics/primitives/8.png");
    this->addPicture(85, 420, "./graphics/primitives/8.png");
    /**/this->addPicture(150, 400, "./graphics/lvl/3s.png");
    this->addPicture(190, 400, "./graphics/primitives/8.png");
    /**/this->addPicture(240, 400, "./graphics/lvl/0s.png");
    this->addPicture(275, 390, "./graphics/primitives/8.png");
    this->addPicture(305, 390, "./graphics/primitives/8.png");
    this->addPicture(320, 405, "./graphics/primitives/8.png");
    this->addPicture(290, 405, "./graphics/primitives/8.png");
    this->addPicture(310, 420, "./graphics/primitives/8.png");
    this->addPicture(325, 425, "./graphics/primitives/8.png");




    this->addPicture(525, 115, "./graphics/lvl/2.png");
    this->addButton(620, 510, LevelEngine::Map, tr("Wróc do mapy"), "");
}
