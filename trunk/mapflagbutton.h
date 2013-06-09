#ifndef MAPFLAGBUTTON_H
#define MAPFLAGBUTTON_H

#include <QObject>

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>

class MapFlagButton : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
	
private:
	QPixmap* unHoverFlag;
	QPixmap* hoverFlag;
	QPixmap* disabledFlag;	
	
	int level;
	
	bool enableFlag;

public:
	explicit MapFlagButton(int x, int y, int lvl, bool enable);
	
	void setFlagEnable(bool flag);
	bool getFlagEnable();
	
private:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

signals:
	void sendFlagLevel(int level);
};

#endif // MAPFLAGBUTTON_H