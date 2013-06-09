#include "graphicsbuttonfrompicture.h"

GraphicsButtonFromPicture::GraphicsButtonFromPicture(int x, int y, int level, const QString& text, const QString& /*path*/):
	AbstractButton(x, y)
{
	//tworzenie graficzek i ładowanie tekstu	
		QPixmap button("./graphics/buttons/iconedButtonUnhover.png");
		QPixmap icon("");
	
		this->text = new QString(text);
		
	//ustawianie czcionków 
		this->normalFont = new QFont("AquilineTwo");
		this->normalFont->setPixelSize(32);
		
	//tworzenie obiektów, ustawianie grafik i pozycjonowanie
	//na scenie
		this->setPixmap(button);
	
		this->ikona = new QGraphicsPixmapItem(icon, this);
		this->tekst = new QGraphicsTextItem(this);
		
		this->tekst->setPlainText(text);
		this->tekst->setFont(*this->normalFont);
		
		this->setPos(x, y);
		this->ikona->setPos(10, 22);
		this->tekst->setPos(30, -10);
	
	//zmiana koloru tekstu oraz czcionki
		QColor bialy(255, 255, 255, 240);
		this->tekst->setDefaultTextColor(bialy);
		
	//ustawiamy, gdzie przycisk ma prowadzić
		this->toLevel = level;

	//pokaż widżety
		
		this->show();
		this->tekst->show();
		this->ikona->show();
}

void GraphicsButtonFromPicture::setText(const QString& text)
{
	this->tekst->setPlainText(text);
}

void GraphicsButtonFromPicture::mousePressEvent(QGraphicsSceneMouseEvent * /*event*/)
{
	//wysyłanie sygnału po naciśnięciu przycisku
		emit clickedSignal(this->toLevel);
}

void GraphicsButtonFromPicture::hoverEnterEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	//zmień mapę pixeli
		QPixmap button("./graphics/buttons/iconedButtonHover.png");
		this->setPixmap(button);
}

void GraphicsButtonFromPicture::hoverLeaveEvent(QGraphicsSceneHoverEvent * /*event*/)
{
	//zmień z powrotem obraz na stary
		QPixmap button("./graphics/buttons/iconedButtonUnhover.png");
		this->setPixmap(button);
}
