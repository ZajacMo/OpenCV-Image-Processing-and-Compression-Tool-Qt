#include "introducewindow.h"
#include "ui_introducewindow.h"

IntroduceWindow::IntroduceWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IntroduceWindow)
{
    ui->setupUi(this);
    // 点击按钮发出回主界面的信号
    connect(ui->mainbtn,&QPushButton::clicked,[=](){
        emit this->returnmain();
    });
    //设置Icon
    QIcon icon(":/new/Resources/head.ico");
    this->setWindowIcon(icon);

}

IntroduceWindow::~IntroduceWindow()
{
    delete ui;

}
