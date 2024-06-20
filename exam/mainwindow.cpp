#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cardwidget.h"
#include "ui_cardwidget.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editPin->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentIndex(0);

    // Initialize card widgets
    for (int i = 0; i < 9; ++i) {
        m_cardWidgets[i] = new cardwidget(this);
        ui->gridLayout->addWidget(m_cardWidgets[i], i / 3, i % 3);

        // Connect cardwidget's button click signal
        connect(m_cardWidgets[i], &cardwidget::cardButtonClicked, this, &MainWindow::handleCardButtonClick);
    }

    // Connect loginButton click signal
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
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
    // Get the sender of the signal (which cardwidget was clicked)
    cardwidget *clickedCard = qobject_cast<cardwidget*>(sender());
    if (!clickedCard)
        return;

    // Show the number in the clicked card, hide numbers in other cards
    for (int i = 0; i < 9; ++i) {
        if (m_cardWidgets[i] == clickedCard) {
            m_cardWidgets[i]->showRandomNumber();
            m_currentCard = m_cardWidgets[i];
        } else {
            m_cardWidgets[i]->hideNumber();
        }
    }
}
