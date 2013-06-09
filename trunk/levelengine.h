#ifndef LEVELENGINE_H
#define LEVELENGINE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QImage>

#include <QString>
#include <QFont>

#include <ctime>
#include <cstdio>

#include "graphicsbuttonfrompicture.h"
#include "graphicsbutton.h"

class LevelEngine : public QObject
{

	Q_OBJECT

/*
		FIELDS
*/
public:
  
  static const int Map = 0;
  
  static const int AdditionWorldLevel1 = 1;
  static const int AdditionWorldLevel2 = 2;
  static const int AdditionWorldLevel3 = 3;
  static const int AdditionWorldLevel4 = 4;
  
  static const int SubtractionWorldLevel1 = 5;
  static const int SubtractionWorldLevel2 = 6;
  static const int SubtractionWorldLevel3 = 7;
  static const int SubtractionWorldLevel4 = 8;
  
  static const int MultiplyWorldLevel1 = 9;
  static const int MultiplyWorldLevel2 = 10;
  static const int MultiplyWorldLevel3 = 11;
  static const int MultiplyWorldLevel4 = 12;
  
  static const int DivisionWorldLevel1 = 13;
  static const int DivisionWorldLevel2 = 14;
  static const int DivisionWorldLevel3 = 15;
  static const int DivisionWorldLevel4 = 16;

protected:
    QGraphicsScene *scena;
	
	QFont *font;
	QColor *fontColor;
	
	int fontSize;
	qreal textWidth;
	
/*
		METHODS
*/

public:
    explicit LevelEngine();
	QGraphicsScene* getScena();
	
	void setFont(const QString& name, int size);
	void setFontColor(int x, int y, int z, int alpha);
	
	void setTextWidthSeparator(qreal number);
	
	void addText(int x, int y, const QString& text);
	void addPicture(int x, int y, const QString& path);
	virtual void addButton(int x, int y, int lvl, const QString& text, const QString& path);
	virtual void addGraphicsButton(int x, int y, int number, bool match, const QString& path);

signals:
	void setLevelSignal(int level);
	
public slots:
	void buttonClicked(int lvl);
};

#endif //LEVELENGINE_H