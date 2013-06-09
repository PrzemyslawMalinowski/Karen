#ifndef MULTIPLICATIONLEVEL4_H
#define MULTIPLICATIONLEVEL4_H

#include <QMessageBox>

#include "multiplicationengine.h"

class MultiplicationLevel4 : public MultiplicationEngine
{
	Q_OBJECT
public:
    explicit MultiplicationLevel4();

    void drawMultiplicationLevel();
	
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

#endif //MULTIPLICATIONLEVEL4_H
