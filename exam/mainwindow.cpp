#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cardwidget.h"
#include "ui_cardwidget.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editPin->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentIndex(0);


    for (int i = 0; i < 9; ++i) {
        m_cardWidgets[i] = new cardwidget(this);
        ui->gridLayout_4->addWidget(m_cardWidgets[i], i / 3, i % 3);
        connect(m_cardWidgets[i], &cardwidget::cardButtonClicked, this, &MainWindow::handleCardButtonClick);
    }

    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
    ui->labelScore->setText("Score: 0");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < 9; ++i) {
        delete m_cardWidgets[i];
    }
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString enteredPin = ui->editPin->text();

    if (enteredPin == m_correctPin) {
        ui->stackedWidget->setCurrentIndex(1);
    } else {
        ui->lblLogin->setText("Неверный пинкод");
        ui->lblLogin->setStyleSheet("color:red;");
    }

    ui->editPin->clear();
}

void MainWindow::handleCardButtonClick(int number)
{
    m_score += number;
    ui->labelScore->setText(QString("Score: %1").arg(m_score));
}

void MainWindow::updateScore(int number)
{
    m_score += number;
    ui->labelScore->setText(QString("Score: %1").arg(m_score));
}
