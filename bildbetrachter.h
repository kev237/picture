
#ifndef BILDBETRACHTER_H
#define BILDBETRACHTER_H
//die Header-Dateien einbinden
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//unsere eigene Klasse erbt von QWidget
class Bildbetrachter : public QWidget
{
//das Makro Q_OBJECT
Q_OBJECT
public:
//der Konstruktor
Bildbetrachter();
//die Slots
private slots:
void oeffneBilddatei(); void waehleDateiAus();
private:
//die Attribute für die Widgets
QLabel* einLabel, *bildLabel;
QLineEdit* eingabeZeile;
QPushButton *oeffnenButton, *beendenButton, *auswaehlenButton;
};
#endif
