#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QGraphicsPixmapItem>
#include <QObject>

class AbstractButton : public QObject, public QGraphicsPixmapItem
{

	Q_OBJECT

	public:
	
		AbstractButton(int x, int y);
		
		void setEnabled(bool tru);
	
	protected:

		int x;
		int y;
		
		bool enable;
	
		virtual void mousePressEvent(QGraphicsSceneMouseEvent * /*event*/){};
		virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * /*event*/){};
		virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * /*event*/){};

};

#endif