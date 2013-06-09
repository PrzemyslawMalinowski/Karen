#ifndef GRAPHICSBUTTONFROMPICTURE_H
#define GRAPHICSBUTTONFROMPICTURE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPixmap>

#include <QString>
#include <QFont>

#include "abstractbutton.h"

class GraphicsButtonFromPicture : public AbstractButton
{

	Q_OBJECT

/*
		FIELDS
*/

private:
	QString *text;
	
	QPixmap *image;
	QPixmap *icon;
	
	QFont *normalFont;
	
	QGraphicsPixmapItem *ikona;
	QGraphicsTextItem *tekst;
	
	int toLevel;

	
/*
		METHODS
*/

public:

    explicit GraphicsButtonFromPicture(int x, int y, int level, const QString& text, const QString& path);
	void setText(const QString& text);	

private:
	
	virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

signals:

	void clickedSignal(int lvl);
};

#endif //GRAPHICSBUTTONFROMPICTURE_H