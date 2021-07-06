#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    picID =2;

    QPixmap pix("D:\\QtP0702\\ObjectTimer\\pic\\1.jpg");
    ui->label->setPixmap(pix);

    this->setMaximumSize(400,350);
    this->setMinimumSize(400,350);
    this->setWindowTitle("LandscapeQObjectTimer");
    //change the background of the button
    ui->startBtn->setStyleSheet("background:#F7FAAD");
    ui->pauseBtn->setStyleSheet("background:#F0DBF1");




}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startBtn_clicked()
{
    //开启定时器，返回定时器编号
     myTimerId = this->startTimer(TIMEOUT);

}
//2
void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() != myTimerId)
        return;
    QString path("D:\\QtP0702\\ObjectTimer\\pic\\");
    path +=QString::number(picID);
    path +=".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picID++;
    if(12 ==picID)
        picID=1;
}
//3
void Widget::on_pauseBtn_clicked()
{
    this->killTimer(myTimerId);

}

