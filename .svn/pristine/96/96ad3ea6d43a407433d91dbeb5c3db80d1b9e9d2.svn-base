#ifndef GRAPHICSBUTTON_H
#define GRAPHICSBUTTON_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

#include <ctime>
#include <cstdio>
#include <Qvector>

#include "abstractbutton.h"


class GraphicsButton : public AbstractButton
{
	Q_OBJECT
	
	/*
		Pola
	*/

	private:
		
		int number;
		
		bool isMatch;
		bool wasEvent;
		
		QVector<QGraphicsPixmapItem*> tab;
		
		
	public:

	/*
		Metody
	*/

		GraphicsButton(int x, int y, int number, bool match, const QString& path);
		
	private:
	
		virtual void mousePressEvent(QGraphicsSceneMouseEvent * event);
		virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
		virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
		
	signals:
		void sendAnsferSignal(bool match);
};

#endif