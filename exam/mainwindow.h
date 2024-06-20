#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cardwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();
    void handleCardButtonClick();

private:
    Ui::MainWindow *ui;
    QString m_correctPin = "1234";
    cardwidget *m_cardWidgets[9];
    cardwidget *m_currentCard = nullptr; // Track the currently active card
};

#endif // MAINWINDOW_H
