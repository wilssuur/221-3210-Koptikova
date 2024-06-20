#include "cardwidget.h"
#include "ui_cardwidget.h"
#include <QRandomGenerator>

cardwidget::cardwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cardwidget)
{
    ui->setupUi(this);
    m_randomNumber = QRandomGenerator::global()->bounded(-70, 100);
}

cardwidget::~cardwidget()
{
    delete ui;
}

void cardwidget::on_pushButton_clicked()
{
    emit cardButtonClicked(m_randomNumber);
}

void cardwidget::showRandomNumber()
{
    ui->label->setText(QString::number(m_randomNumber));
    ui->label->setVisible(true);
}

void cardwidget::hideNumber()
{
    ui->label->setVisible(false);
}
