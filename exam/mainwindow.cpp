#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editPin->setEchoMode(QLineEdit::Password);
    ui->stackedWidget->setCurrentIndex(1);

    // Подключаем сигнал нажатия кнопки к слоту
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString enteredPin = ui->editPin->text();

    if (m_isStartup) {
        if (enteredPin == m_correctPin) {
            ui->stackedWidget->setCurrentIndex(0);
            m_isStartup = false;
        } else {
            ui->lblLogin->setText("Неверный пинкод");
            ui->lblLogin->setStyleSheet("color:red;");
        }
    }

    ui->editPin->clear();
}
