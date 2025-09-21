#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
    // 点击按钮发出回主界面的信号
    connect(ui->mainbtn,&QPushButton::clicked,[=](){
        emit this->returnmain();
    });
    // 点击按钮发出去解压缩界面的信号
    connect(ui->unbtn,&QPushButton::clicked,[=](){
        emit this->touncompress();
    });
    // 点击按钮发出去压缩界面的信号
    connect(ui->compressbtn,&QPushButton::clicked,[=](){
        emit this->tocompress();
    });
    //设置Icon
    QIcon icon(":/new/Resources/head.ico");
    this->setWindowIcon(icon);

}

HelpWindow::~HelpWindow()
{
    delete ui;
}
