#ifndef DIVISIONENGINE_H
#define DIVISIONENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QImage>

#include <QString>
#include <QFont>

#include "levelengine.h"

class DivisionEngine : public LevelEngine
{
    /*

      FIELDS

      */
	  
    Q_OBJECT


    /*

      METHODS

    */
	
public:
    explicit DivisionEngine();
	
};

#endif // DIVISIONENGINE_H