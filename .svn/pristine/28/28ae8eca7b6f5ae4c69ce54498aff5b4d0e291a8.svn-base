#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QMessageBox>
#include <QString>

#include "logindialog.h"
#include "flagscontainer.h"
#include "levelengine.h"

#include "mapscene.h"
#include "flagscontainer.h"

//levele ze świata dodawania 
#include "additionlevel1.h"
#include "additionlevel2.h"
#include "additionlevel3.h"
#include "additionlevel4.h"

//levele ze świata odejmowani
#include "sublevel1.h"
#include "sublevel2.h"
#include "sublevel3.h"
#include "sublevel4.h"

//levele ze świata mnożenia
#include "multiplicationlevel1.h"
#include "multiplicationlevel2.h"
#include "multiplicationlevel3.h"
#include "multiplicationlevel4.h"

//levele ze świata dzielenia
#include "divisionlevel1.h"
#include "divisionlevel2.h"
#include "divisionlevel3.h"
#include "divisionlevel4.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    /*

      FIELDS

      */
	  
    Q_OBJECT

private:
    QGraphicsScene *scena;
	QString user;
	
	FlagsContainer *kontenerFlag;
	
	//int ansfers;

    /*

      METHODS

    */
public:
    explicit MainWindow(QString player, QWidget *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    ~MainWindow();
	
public slots:
	void setScene(int lvl);
	void unlockWorld(bool match);

protected:
	void run();
	
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
