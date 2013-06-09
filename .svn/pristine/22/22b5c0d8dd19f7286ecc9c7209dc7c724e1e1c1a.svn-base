#include "logindialog.h"

/**
*@name
*	LoginDialog
*@param
*	parent - wskaźnik do ojca okna
*
*	Konstruktor okna dialogowego
*	ustawia on tytuł, tryb dla wczytującej lini 
*	oraz ukrywa widget z dodawaniem nowego uzytkownika
*	Potem uruchania operacje na tym oknie
*/

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
	
	this->setWindowTitle(tr("Zaloguj się :)"));
	this->lineEdit->setEchoMode(QLineEdit::Password);
	
	this->widget_2->setVisible(false);
	this->widget_2->setGeometry(10,10,221,201);
	
	this->comboBox->setDuplicatesEnabled(false);
	
	this->run();
}

/**
*@name
*	run
*@param
*	void
*@return
*	void
*
*	Ta część odpowiada za pierwsze wczytanie użytkowników
*	do comboboxa, oraz obsługuje sygnały i sloty dla
*	tego okna
*/

void LoginDialog::run()
{
	if(this->readUsersFromFile())
		this->comboBox->addItems(this->list);
	else
	{
		QMessageBox message;
		message.setText("Błąd przy ładowaniu danych! Zaraz zakończę działanie");
		message.exec();
	}
	
	QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(login()));
	QObject::connect(newButton, SIGNAL(clicked()), this, SLOT(showAddingWidget()));
	QObject::connect(cancelAddingButton, SIGNAL(clicked()), this, SLOT(showMainWidget()));
	QObject::connect(okAddButton, SIGNAL(clicked()), this, SLOT(addNewUser()));
	
	QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(closeDialog()));
	QObject::connect(this, SIGNAL(close(int)), this, SLOT(done(int)));
}

/**
*@name
*	closeDialog
*@param
*	void
*@return
*	void
*@type
*	slot
*
*	Slot ten odpowiada za dwie akcje: pierwsza
*	do utworzenie dialogu "czy chcesz wyjść..." i obsłużenie go.
*	Druga akcja to wysłanie sygnału do wyłączenia dialogu, jeżeli
*	użytkownik potwierdzi taką chęć
*
*/

void LoginDialog::closeDialog()
{
	 QMessageBox msgBox;
	 msgBox.setWindowTitle(tr("Pytanie"));
	 msgBox.setText(tr("Czy naprawdę chcesz wyjść z gry?"));
	 msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	 msgBox.setDefaultButton(QMessageBox::Cancel);
	 
	 int wybor = msgBox.exec();
	 
	 if(wybor == QMessageBox::Ok)
		emit close(Closed);
}

/**
*@name
*	clearEditLines
*@param
*	void
*@return
*	void
*
*	Czyści wszystkie edytory linii tekstu.
*	Jest to potrzebne przy przełączaniu widgetów
*
*/

void LoginDialog::clearEditLines()
{
	this->lineEdit->clear();
	this->newPassLine->clear();
	this->newUserLine->clear();
}

/**
*@name
*	showAddingWidget
*@param
*	void
*@return
*	void
*
*	Pokazuje widget dodawania i chowa widget
*	logowania. 
*
*/

void LoginDialog::showAddingWidget()
{
	this->clearEditLines();

	this->widget->setVisible(false);
	this->widget_2->setVisible(true);
}

/**
*@name
*	login
*@param
*	void
*@return
*	void
*
*	loguje użytkownika lub też nie. jeżeli zaloguje to wysyła odpowiedni sygnał.
*
*/

void LoginDialog::login()
{
	if(this->validateData() == true)
	{
	
		QMessageBox p;
		p.setWindowTitle(tr("Dzień dobry :)"));
		p.setText(tr("Zalogowano poprawnie :)"));
		p.exec();
		
		loggedUser = this->comboBox->currentText();
		
		emit close(Done);
		
	}	
	else
	{
	
		QMessageBox p;
		p.setWindowTitle(tr("Błąd"));
		p.setText(tr("Złe hasło. Podaj je ponownie"));
		p.exec();
		
	}
}


/**
*@name
*	showMainWidget
*@param
*	void
*@return	
*	void
*
*	Chowa widget dodawania uzytkownika i pokazuje
*	widget logowania
*
*/

void LoginDialog::showMainWidget()
{
	this->clearEditLines();

	this->widget_2->setVisible(false);
	this->widget->setVisible(true);
}

/**
*@name
*	validateData
*@param
*	void
*@return
*	true - jeżeli użytkownik jest zalogowany
*	false - gdy nie jest
*@type
*	slot
*
*	Ten slot pobiera dane comboboxa i z edycji linii i porównuje
*	je do danych na dysku - jeżeli wszystko jest ok (czyli zgadza się użytkownik i hasło)
*	to zwraca true. W inyym przaypadku false
*
*/

bool LoginDialog::validateData()
{
	QString user = this->comboBox->currentText();
	QString pass = this->lineEdit->text();
	QString buffer;
	
	QString filename = "./users/passwords/" + user + ".dat";
	QFile file(filename);
	
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream( &file );
		
		stream >> buffer;
		
		file.close();
	}
	else
	{
		QMessageBox p;
		p.setWindowTitle(tr("Błąd"));
		p.setText(tr("Błąd! Problem krytyczny z plikiem\nhaseł użytkownika ") + user);
		p.exec();
		
		return false;
	}

	if(pass == buffer)
		return true;
	
	return false;
}

/**
*@name
*	addNewUser
*@param
*	void
*@return
*	void
*@type
*	slot
*
*	Slot ten pobiera dane z edycji linii i stara się je zapisać na
*	dysku twardym, a następnie - gdy wszystko pójdzie zgodnie z planem - odświeża
*	dane w comboboxie
*	
*/

bool LoginDialog::addNewUser()
{
	QString user = this->newUserLine->text();
	QString pass = this->newPassLine->text();
	
	QString buffer;
	QString lamer;
	
	/*
		Dodawanie nowego uzytkownika
	*/
	
	QString filename = "./users/users.dat";
	QFile file(filename);
	QSet<QString> uzytkownicy;
	
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream( &file );
		QStringList users;
		
		while(!stream.atEnd()){
			stream >> buffer;
			uzytkownicy.insert(buffer);
		}
		file.close();
		
		if(!uzytkownicy.contains(user)){
			uzytkownicy.insert(user);
		}
		else
		{
			QMessageBox p;
			p.setWindowTitle(tr("Błąd"));
			p.setText(tr("Już taki użytkownik istnieje!"));
			p.exec();
			return false;
		}
		
		QTextStream stream2( &file );
		
		if (file.open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QSetIterator<QString> i(uzytkownicy);
			 
			while (i.hasNext())
				stream2 << i.next() << "\n";
				
			file.close();
		}
		
		file.close();
	}
	else
	{
		QMessageBox p;
		p.setWindowTitle(tr("Błąd"));
		p.setText(tr("Błąd! Problem krytyczny z plikiem users.dat"));
		p.exec();
		
		this->showMainWidget();
		
		return false;
	}

	/*
		Generowanie hasła
	*/
	
	filename = "./users/passwords/" + user + ".dat";
	QFile file2(filename);
	
	if (file2.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream stream2( &file2 );
		
		stream2 << pass;
		
		file2.close();
	}
	else
	{
		QMessageBox p;
		p.setWindowTitle(tr("Błąd"));
		p.setText(tr("Błąd! Problem krytyczny z tworzeniem\nplikiem haseł użytkownika ") + user);
		p.exec();
		
		return false;
	}
	
	/*
		Generowanie pliku z flagami
	*/
	
	filename = "./users/flags/" + user + ".dat";
	QFile file3(filename);
	
	if (file3.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream stream3( &file3 );
		
		stream3 << 1 << "\n";
		
		for(int i = 0; i < 15; i++)
			stream3 << 0 << "\n";
		
		file3.close();
	}
	else
	{
		QMessageBox p;
		p.setWindowTitle(tr("Błąd"));
		p.setText(tr("Błąd! Problem krytyczny z tworzeniem rejestru flag"));
		p.exec();
		
		this->showMainWidget();
		
		return false;
	}
	
	this->readUsersFromFile();
	this->comboBox->clear();
	this->comboBox->addItems(this->list);
	this->showMainWidget();
	
	QMessageBox p;
	p.setWindowTitle("Informacja");
	p.setText(tr("Nowy użytkownik został dodany :)"));
	p.exec();
	
	return true;
}

/**
*@name
*	readUsersFromFile
*@param
*	void
*@return
*	true - jeżeli wszystko będzie ok i lista będzie wczytana poprawnie
*	false - w innym przypadku
*
*	Metoda ta odpowiada za wczytanie poprawnie listy użytkowników do QStringList
*	Na początku czyści tą listę (żeby nie było powtórzeń), wczytuje ona następnie dane z dysku.
*	Ta lista jest potrzebna do obsługi comboboxa.
*
*/

bool LoginDialog::readUsersFromFile()
{
	QString buffer; 
	QString filename = "./users/users.dat";
	
	list.clear();
	
	QFile file(filename);
	
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream stream( &file );
		
		while(!stream.atEnd())
		{
			stream >> buffer;
			if(buffer != "")
				list.append(buffer);
		}
		
		file.close();
		
		list.sort();
	}
	else
	{
		QMessageBox p;
		p.setText("Błąd przy otwieraniu pliku users.dat");
		p.exec();
		
		return false;
	}
	
	return true;
}

/**
*@name
*	getLoggedUser
*@param
*	void
*@return
*	QString - zwraca nazwę zalogowanego użytkownika
*
*	Po weryfikacji użytkownika można użyć tej funkcji do
*	pobrania nazwy zalogowanego użytkownika
*
*/

QString LoginDialog::getLoggedUser()
{
	return loggedUser;
}

/**
*@name
*	~LoginDialog
*
*	Destruktor
*/

LoginDialog::~LoginDialog()
{
}