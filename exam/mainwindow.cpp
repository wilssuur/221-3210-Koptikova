#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cardwidget.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    ui->labelScore->setText("0");

    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetGameField);
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
void MainWindow::handleCardButtonClick()
{
    cardwidget *clickedCard = qobject_cast<cardwidget*>(sender());
    if (!clickedCard)
        return;
    for (int i = 0; i < 9; ++i) {
        if (m_cardWidgets[i] == clickedCard) {
            m_cardWidgets[i]->showRandomNumber();
            m_currentCard = m_cardWidgets[i];
            ++visibleCount;
        } else {
            m_cardWidgets[i]->hideNumber();
        }
    }

    m_currentScore += clickedCard->cardValue();
    ui->labelScore->setText(QString::number(m_currentScore));

    if (visibleCount == 3) {
        showScoreMessage();
        resetGameField();
        visibleCount = 0;
    }
}

void MainWindow::resetGameField()
{
    m_currentScore = 0;
    for (int i = 0; i < 9; ++i) {
        m_cardWidgets[i]->hideNumber();
        m_cardWidgets[i]->generateRandomNumber();
    }
    ui->labelScore->setText("0");
}

void MainWindow::showScoreMessage()
{
    QString message = QString("Сумма выбранных карт: %1").arg(m_currentScore);
    QMessageBox::information(this, "Результат", message);
}
