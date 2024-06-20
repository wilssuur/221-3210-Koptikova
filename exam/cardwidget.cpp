#include "cardwidget.h"
#include "ui_cardwidget.h"
#include <QRandomGenerator>

cardwidget::cardwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardwidget)
{
    ui->setupUi(this);
    // Generate a random number
    int randomNumber = QRandomGenerator::global()->bounded(-100, 100); // Random number between -100 and 99
    ui->label->setText(QString::number(randomNumber)); // Assuming label to display number is named label
}

cardwidget::~cardwidget()
{
    delete ui;
}
