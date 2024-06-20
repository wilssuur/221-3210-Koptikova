#include "cardwidget.h"
#include "ui_cardwidget.h"

cardwidget::cardwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardwidget)
{
    ui->setupUi(this);
    generateRandomNumber();
}

cardwidget::~cardwidget()
{
    delete ui;
}

void cardwidget::on_pushButton_clicked()
{
    emit cardButtonClicked();
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

int cardwidget::cardValue() const
{
    return m_randomNumber;
}


void cardwidget::generateRandomNumber()
{
    m_randomNumber = rand() % 21 - 10;
}
