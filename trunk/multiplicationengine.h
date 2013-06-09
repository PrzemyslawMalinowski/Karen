#ifndef MULTIPLICATIONENGINE_H
#define MULTIPLICATIONENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QImage>

#include <QString>
#include <QFont>

#include "levelengine.h"

class MultiplicationEngine : public LevelEngine
{
    /*

      FIELDS

      */

    Q_OBJECT


    /*

      METHODS

    */

public:
    explicit MultiplicationEngine();

};

#endif // MULTIPLICATIONENGINE_H
