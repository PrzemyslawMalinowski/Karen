#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QStringList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
#include <QSet>

#include "ui_logindialog.h"

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog, private Ui_Dialog
{
    Q_OBJECT

private:
	QStringList list;
	QString loggedUser;

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
	
	void clearEditLines();
	
	static const int Done = 0;
	static const int Rejected = 1;
	static const int Closed = 4;
	
	QString getLoggedUser();
	
protected:
	void run();
	bool readUsersFromFile();

	
protected slots:
	bool validateData();
	void showAddingWidget();
	void showMainWidget();
	bool addNewUser();
	void closeDialog();
	void login();
	
signals:
	void close(int signal);
};

#endif // LOGINDIALOG_H
