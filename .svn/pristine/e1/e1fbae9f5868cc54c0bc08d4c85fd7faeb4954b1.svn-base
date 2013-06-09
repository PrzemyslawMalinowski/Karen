#ifndef SUBLEVEL4_H
#define SUBLEVEL4_H

#include "subengine.h"
#include <QMessageBox>

/**
*@name 
*	SubLevel
*
*	Klasa która tworzy pattern dla sceny
*	obsługującej level 4 z świata dodawania
*/

class SubLevel4 : public SubEngine
{

	Q_OBJECT

public:
    explicit SubLevel4();
	void drawSubLevel();
	void clear();
	virtual void addGraphicsButton(int x, int y, int number, bool match, const QString& path);
	
private:
	int randomizeNotLike(int liczba);
	void draw();
	
	int proby;
	
public slots:
	void sendAnsferSlot(bool match);
	
signals:
	void isMatchedSignal(bool match);
	
	
};

#endif
