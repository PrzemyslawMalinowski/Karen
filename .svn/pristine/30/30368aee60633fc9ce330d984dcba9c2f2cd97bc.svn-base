#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QImage>
#include <QMessageBox>

#include <QFont>

#include "mapflagbutton.h"
#include "levelengine.h"
#include "flagscontainer.h"

#include "graphicsbutton.h"

class MapScene : public QObject
{
	  
    Q_OBJECT

	/*

      FIELDS

      */
	
private:
    QGraphicsScene *scena;
	FlagsContainer *flags;
    /*

      METHODS

    */
	
public:
    explicit MapScene(FlagsContainer *flags);
	
	QGraphicsScene* getScena();
	void drawMap();
	
private:
	void addFlagToMap(int x, int y, int lvl, bool enable);
	void addGraphicsButton(int x, int y, int number, bool match, const QString& name);
	
signals:
	void sendFlagAsGameLevel(int level);
	
public slots:
	void getFlagAndSendThemAway(int level);
};

#endif //MAPSCENE_H