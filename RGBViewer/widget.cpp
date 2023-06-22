#include "widget.h"
#include "ui_widget.h"

#include <QStringListModel>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listColor->setModel(new QStringListModel(QColor::colorNames()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::RGBAdjust()
{
    int r=ui->verticalSliderR->value();
    int g=ui->verticalSliderG->value();
    int b=ui->verticalSliderB->value();
    QPalette pal;
    pal.setColor(QPalette::Window, QColor(r, g, b));
    pal.setColor(QPalette::WindowText, QColor(255-r, 255-g, 255-b));
    ui->labelRGB->setPalette(pal);
    on_spinBoxR_valueChanged(ui->spinBoxR->value());
    on_spinBoxG_valueChanged(ui->spinBoxG->value());
    on_spinBoxB_valueChanged(ui->spinBoxB->value());
}

void Widget::on_spinBoxR_valueChanged(int val)
{
    QPalette pal;
    QColor c(val,0,0);
    if(ui->radioButtonCMY->isChecked())
        c.setCmyk(val,0,0,0);
    pal.setColor(QPalette::Base, c);
    if(ui->radioButtonRGB->isChecked())
        c.setRgb(0,255,255);
    else
        c.setCmyk(0,255,255,0);
    pal.setColor(QPalette::Text, c);
    ui->spinBoxR->setPalette(pal);
    RGBAdjust();
}

void Widget::on_spinBoxG_valueChanged(int val)
{
    QPalette pal;
    QColor c(0,val,0);
    if(ui->radioButtonCMY->isChecked())
        c.setCmyk(0,val,0,0);
    pal.setColor(QPalette::Base, c);
    if(ui->radioButtonRGB->isChecked())
        c.setRgb(255,0,255);
    else
        c.setCmyk(255,0,255,0);
    pal.setColor(QPalette::Text, c);
    ui->spinBoxG->setPalette(pal);
    RGBAdjust();
}

void Widget::on_spinBoxB_valueChanged(int val)
{
    QPalette pal;
    QColor c(0,0,val);
    if(ui->radioButtonCMY->isChecked())
        c.setCmyk(0,0,val,0);
    pal.setColor(QPalette::Base, c);
    if(ui->radioButtonRGB->isChecked())
        c.setRgb(255,255,0);
    else
        c.setCmyk(255,255,0,0);
    pal.setColor(QPalette::Text, c);
    ui->spinBoxB->setPalette(pal);
    RGBAdjust();
}

void Widget::on_listColor_clicked(const QModelIndex &index)
{
    QColor c(index.data().toString());
        ui->spinBoxR->setValue(c.red());
        ui->spinBoxG->setValue(c.green());
        ui->spinBoxB->setValue(c.blue());

}

void Widget::on_radioButtonRGB_clicked()
{
    ui->labelRGB->setText("RGB");
    on_spinBoxR_valueChanged(ui->spinBoxR->value());
    on_spinBoxG_valueChanged(ui->spinBoxG->value());
    on_spinBoxB_valueChanged(ui->spinBoxB->value());
}

void Widget::on_radioButtonCMY_clicked()
{
    ui->labelRGB->setText("CMY");
    on_spinBoxR_valueChanged(ui->spinBoxR->value());
    on_spinBoxG_valueChanged(ui->spinBoxG->value());
    on_spinBoxB_valueChanged(ui->spinBoxB->value());
}
