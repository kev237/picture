 //die Header-Dateien einbinden
#include "bildbetrachter.h"
#include <QPixmap>
#include <QMessageBox>
#include <QFileDialog>

//der Konstruktor
Bildbetrachter::Bildbetrachter()
{

//die Größe und den Titel setzen
    resize(500,280);
    setWindowTitle("Bildbetrachter");

//die Widgets erzeugen und positionieren
    eingabeZeile = new QLineEdit(this);
    eingabeZeile->setGeometry(10, 200, 200, 30);

//bitte in einer Zeile eingeben
    einLabel = new QLabel("Bitte geben Sie den Dateinamen ein:", this);
    einLabel->setGeometry(10, 180, 230, 30);
    bildLabel = new QLabel(this);
    bildLabel->setGeometry(10, 10, 10, 10);
    oeffnenButton = new QPushButton(this);
    oeffnenButton->setGeometry(250, 200, 70, 30);
    oeffnenButton->setText("Öffnen");

//den Öffnen-Button mit dem Slot verbinden
    //bitte in einer Zeile eingeben
    QObject::connect(oeffnenButton, SIGNAL(clicked()),this, SLOT(oeffneBilddatei()));
    //der Beenden-Button
    beendenButton = new QPushButton(this);
    beendenButton->setGeometry(350, 200, 70, 30);
    beendenButton->setText("Beenden");

//bitte in einer Zeile eingeben
    QObject::connect(beendenButton, SIGNAL(clicked()),this, SLOT(close()));
    //der Auswählen-Button
    auswaehlenButton = new QPushButton(this);
    auswaehlenButton->setGeometry(250, 170, 70, 30);
    auswaehlenButton->setText("Auswählen");
    //bitte in einer Zeile eingeben
    QObject::connect(auswaehlenButton, SIGNAL(clicked()),this, SLOT(waehleDateiAus()));
}

    void Bildbetrachter::oeffneBilddatei()
    {
        QPixmap bild;
        //konnte das Bild geladen werden?
        //dann anzeigen
        if (bild.load(eingabeZeile->text()))
        {
            //die Größe wird dabei an die Breite 150 angepasst
            bild = bild.scaledToWidth(150);
            //im Label anzeigen
            bildLabel->setPixmap(bild);
            //die Größe des Labels an die Größe des Bildes 
            //anpassen
            bildLabel->resize(bild.size());
        }else {QMessageBox::critical(this, "Fehler beim Öffnen der Datei", "Die Grafikdatei konnte nicht geöffnet werden.\nBitte geben Sie den Dateinamen mit Pfad in das Textfeld ein.");}
    }

    void Bildbetrachter::waehleDateiAus()
    {
        QString datei;
        //den Dialog anzeigen und die Auswahl ablegen
        //bitte in einer Zeile eingeben
        datei = QFileDialog::getOpenFileName(this, "bitte Datei öffnen",QDir::currentPath(), "Grafikdateien (*.jpg *.bmp *.gif*.png *.jpeg)");
        //wurde eine Datei ausgewählt?
        if (datei.isEmpty() == false)
        {
            eingabeZeile->setText(datei);
            oeffneBilddatei();
        }
    }
