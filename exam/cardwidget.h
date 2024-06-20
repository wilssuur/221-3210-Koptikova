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

private:
    Ui::cardwidget *ui;
};

#endif // CARDWIDGET_H
