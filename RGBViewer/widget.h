#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void RGBAdjust();

private slots:
    void on_spinBoxR_valueChanged(int arg1);

    void on_spinBoxG_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);

    void on_listColor_clicked(const QModelIndex &index);

    void on_radioButtonRGB_clicked();

    void on_radioButtonCMY_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
