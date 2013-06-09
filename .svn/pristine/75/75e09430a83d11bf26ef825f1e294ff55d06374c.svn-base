#ifndef ADDITIONLEVEL4_H
#define ADDITIONLEVEL4_H

#include "additionengine.h"
#include <QMessageBox>

/**
*@name 
*	AdditionLevel
*
*	Klasa która tworzy pattern dla sceny
*	obsługującej level 4 z świata dodawania
*/

class AdditionLevel4 : public AdditionEngine
{

	Q_OBJECT

public:
    explicit AdditionLevel4();
	void drawAdditionLevel();
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

#endif //ADDITIONLEVEL3ź_H