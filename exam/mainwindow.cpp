#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editPin->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentIndex(0);

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

    if (m_isStartup) {
        if (enteredPin == m_correctPin) {
            ui->stackedWidget->setCurrentIndex(1);
            m_isStartup = false;
            for (int i = 0; i < 9; ++i) {
                m_cardWidgets[i] = new cardwidget(this);
                ui->gridLayout->addWidget(m_cardWidgets[i], i / 3, i % 3);
            }

            connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
        } else {
            ui->lblLogin->setText("Неверный пинкод");
            ui->lblLogin->setStyleSheet("color:red;");
        }
    }

    ui->editPin->clear();
}
