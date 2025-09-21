#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPushButton>
#include<opencv2/opencv.hpp>
#include<QFileDialog>
#include"compresswindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->pcompress=new CompressWindow;
    // 收到信号切换为压缩界面
    connect(ui->compressbtn,&QPushButton::clicked,[=](){
        this->hide();
        this->pcompress->show();
    });
    // 收到信号切换回主界面
    connect(this->pcompress,&CompressWindow::returnmain,[=](){
        this->pcompress->hide();
        this->show();
    });
    // 收到信号切换为解压缩界面
    connect(this->pcompress,&CompressWindow::touncompress,[=](){
        this->pcompress->hide();
        this->puncompress->show();
    });
    // 收到信号切换为帮助界面
    connect(this->pcompress,&CompressWindow::tohelp,[=](){
        this->pcompress->hide();
        this->phelp->show();
    });
    this->phelp=new HelpWindow;
    // 收到信号切换为帮助界面
    connect(ui->helpbtn,&QPushButton::clicked,[=](){
        this->hide();
        this->phelp->show();
    });
    // 收到信号切换回主界面
    connect(this->phelp,&HelpWindow::returnmain,[=](){
        this->phelp->hide();
        this->show();
    });
    // 收到信号切换为解压缩界面
    connect(this->phelp,&HelpWindow::touncompress,[=](){
        this->phelp->hide();
        this->puncompress->show();
    });
    // 收到信号切换为压缩界面
    connect(this->phelp,&HelpWindow::tocompress,[=](){
        this->phelp->hide();
        this->pcompress->show();
    });
    this->pintroduce=new IntroduceWindow;
    // 收到信号切换为介绍界面
    connect(ui->introducebtn,&QPushButton::clicked,[=](){
        this->hide();
        this->pintroduce->show();
    });
    // 收到信号切换回主界面
    connect(this->pintroduce,&IntroduceWindow::returnmain,[=](){
        this->pintroduce->hide();
        this->show();
    });
    this->puncompress=new uncompressWindow;
    // 收到信号切换为解压缩界面
    connect(ui->uncompressbtn,&QPushButton::clicked,[=](){
        this->hide();
        this->puncompress->show();
    });
    // 收到信号切换回主界面
    connect(this->puncompress,&uncompressWindow::returnmain,[=](){
        this->puncompress->hide();
        this->show();
    });
    // 收到信号切换为帮助界面
    connect(this->puncompress,&uncompressWindow::tohelp,[=](){
        this->puncompress->hide();
        this->phelp->show();
    });
    // 收到信号切换为压缩界面
    connect(this->puncompress,&uncompressWindow::tocompress,[=](){
        this->puncompress->hide();
        this->pcompress->show();
    });
    //设置Icon
    QIcon icon(":/new/Resources/head.ico");
    this->setWindowIcon(icon);


}

MainWindow::~MainWindow()
{
    delete ui;
}
