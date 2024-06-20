#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

namespace Ui {
class cardwidget;
}

class cardwidget : public QWidget
{
    Q_OBJECT

public:
    explicit cardwidget(QWidget *parent = nullptr);
    ~cardwidget();

    void showRandomNumber();
    void hideNumber();

signals:
    void cardButtonClicked(int number);

private slots:
    void on_pushButton_clicked();

private:
    Ui::cardwidget *ui;
    int m_randomNumber;
};

#endif // CARDWIDGET_H
