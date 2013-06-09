
#ifndef SUBENGINE_H
#define SUBENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QImage>

#include <QString>
#include <QFont>

#include "levelengine.h"

class SubEngine : public LevelEngine
{
    /*

      FIELDS

      */
	  
    Q_OBJECT


    /*

      METHODS

    */
	
public:
    explicit SubEngine();
	
};

#endif // SUBTRACTIONENGINE_H
