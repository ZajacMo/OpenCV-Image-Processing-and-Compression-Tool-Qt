#include "uncompresswindow.h"
#include "ui_uncompresswindow.h"
#include <qmessagebox.h>

uncompressWindow::uncompressWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::uncompressWindow)
{
    ui->setupUi(this);
    // 点击按钮发出回主界面的信号
    connect(ui->mainbtn,&QPushButton::clicked,[=](){
        emit this->returnmain();
    });
    // 点击按钮发出去帮助界面的信号
    connect(ui->helpbtn,&QPushButton::clicked,[=](){
        emit this->tohelp();
    });
    // 点击按钮发出去压缩界面的信号
    connect(ui->compressbtn,&QPushButton::clicked,[=](){
        emit this->tocompress();
    });
    QIcon icon(":/new/Resources/head.ico");
    this->setWindowIcon(icon);
}

uncompressWindow::~uncompressWindow()
{
    delete ui;
    if(ucg)
        delete ucg;
}

// 选择需要解码的文件
void uncompressWindow::on_choosebtn_clicked()
{
    if(ucg)
        delete ucg;
    ucg = new Compress_gray();
    fileName = QFileDialog::getOpenFileName(this, "选择需要解码的文件",
                                                    "/result.nam",
                                                    tr("Images (*.nam)"));
    ui->lineEdit->setText(fileName);
    ucg->init_uncompress(fileName.toStdString());
    ui->formerSize->setText(QString::number(ucg->getReadLen()/8)+" Bytes");
}


// 保存解压后的图片
void uncompressWindow::on_savebtn_clicked()
{
    if(ucg->getReadLen() == 0)
    {
        QMessageBox::warning(this,"Error","Please choose a file first!");
        return;
    }
    if(ucg->getReadLen() == 0)
    {
        QMessageBox::warning(this,"Error","Please choose a file first!");
        return;
    }
    QString savePath = QFileDialog::getSaveFileName(this,tr("Save Image"), "Desktop/uncompressedIMG.bmp");
    cv::imwrite(savePath.toStdString(), ucg->result);
}


void uncompressWindow::on_runbtn_clicked()
{
    if(fileName.isEmpty()){
        QMessageBox::warning(this,"Error","Please choose a file first!");
        return;
    }
    cv::Mat res = ucg->uncompress();
    ui->uncompressTime->setText(QString::number(ucg->getTime(),'g',6)+" s");
    QString size = QString::number(res.rows)+"*"+QString::number(res.cols);
    if(ucg->isColorful)
        size += "*3";
    size += " Bytes";
    ui->newSize->setText(size);

    QImage m_imgSrc = QImage((const unsigned char*)(res.data),res.cols,res.rows,res.cols,QImage::Format_Grayscale8);

    QImage m_img2show = m_imgSrc.scaled(ui->photo->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap m_pix2show=QPixmap::fromImage(m_img2show);

    ui->photo->setPixmap(m_pix2show);

    ui->rate->setText(QString::number(ucg->getRate(),'g',6));
}

