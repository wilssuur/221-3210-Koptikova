#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked(); // Слот для нажатия на кнопку "Вход"

private:
    Ui::MainWindow *ui;
    bool m_isStartup = true;
    QString m_correctPin = "1234"; // Заданный пин-код
};

#endif // MAINWINDOW_H
