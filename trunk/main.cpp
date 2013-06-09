#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFontDatabase>
#include <QMessageBox>

#include "logindialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    //ustawienie programu
	
		//kodowanie programu:
			QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
			
		//Wczytywanie czcionek:
			if( QFontDatabase::addApplicationFont ("./graphics/fonts/AquilineTwo.ttf") < 0 ){
				QMessageBox error;
				error.setText("Nie wczytano czcionek, więc ustawiam domyślne");
				error.exec();
			}
	
	//wyświetlenie programu
	
		LoginDialog login;	
		int result = login.exec();
		
		MainWindow w(login.getLoggedUser());
		
		if(result == LoginDialog::Done)	
			w.show();
	
    return a.exec();
}
