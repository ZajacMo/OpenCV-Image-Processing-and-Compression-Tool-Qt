#include "compresswindow.h"
#include "ui_compresswindow.h"
#include <QPushButton>
#include <QCoreApplication>
#include <QDataStream>
#include <operatorsignals.cpp>

CompressWindow::CompressWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CompressWindow)
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
    // 点击按钮发出去帮助界面的信号
    connect(ui->helpbtn,&QPushButton::clicked,[=](){
        emit this->tohelp();
    });
    //设置Icon
    QIcon icon(":/new/Resources/head.ico");
    this->setWindowIcon(icon);
    cg = new Compress_gray;

}

CompressWindow::~CompressWindow()
{
    delete ui;
    delete cg;
}
void CompressWindow::resizeEvent(QResizeEvent* event)/*显示图片的槽函数*/
{
    m_img2show = m_imgSrc.scaled(ui->firstphoto->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    m_pix2show=QPixmap::fromImage(m_img2show);

    ui->firstphoto->setPixmap(m_pix2show);
}



void CompressWindow::on_runbtn_clicked()
{
    if(strFileName.isEmpty())
    {
        QMessageBox::warning(this,"Error","Please choose a photo first!");
        return;
    }
    sigma = ui->doubleSpinBox->value();
    if(cg)
        delete cg;
    cg = new Compress_gray;
    //载入图片
    cg->init_compress(cv::imread(strFileName.toStdString(),isColorful),sigma);
    //原图大小
    QString size = QString::number(cg->img.rows)+"*"+QString::number(cg->img.cols);
    if(isColorful)
        size += "*3";
    size += "Bytes";
    ui->formerSize->setText(size);
    //压缩
    cg->compress();
    //显示压缩率
    ui->compressRate->setText(QString::number(cg->getRate()));
    //显示压缩时间
    ui->compressTime->setText(QString::number(cg->getTime(),'g',6)+" s");
    //显示压缩后大小
    ui->newSize->setText(QString::number(cg->getWriteLen()/8)+" Bytes");
}


void CompressWindow::on_savebtn_clicked()
{
    if(!cg||cg->isNull)
    {
        QMessageBox::warning(this,"Error","Please compress first!");
        return;
    }
    savePath = QFileDialog::getSaveFileName(this,tr("Save Image"), "Desktop/result.nam");
    cg->save(savePath.toStdString());
}


void CompressWindow::on_colorfulphoto_clicked()
{
    isColorful=1;
}


void CompressWindow::on_blackphoto_clicked()
{
    isColorful=0;
}

    // 点击按钮选择图片导入
void CompressWindow::on_choosebtn_clicked()
{
    strFileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "lena512.bmp", tr("Image Files (*.png *.jpg *.bmp)"));
    m_imgSrc.load(strFileName);
    m_img2show = m_imgSrc.scaled(ui->firstphoto->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    m_pix2show=QPixmap::fromImage(m_img2show);

    ui->firstphoto->setPixmap(m_pix2show);

    ui->secondlphoto->clear();

}

// 点击按钮解压缩
void CompressWindow::on_uncompressBtn_clicked()
{
    if(strFileName.isEmpty())
    {
        QMessageBox::warning(this,"Error","Please choose a photo first!");
        return;
    }
    cg->save("compressed.nam");
    Compress_gray ucg;
    ucg.init_uncompress("compressed.nam");

    cv::Mat result = ucg.uncompress();

    m_img2show = QImage((const unsigned char*)(result.data),result.cols,result.rows,result.cols,QImage::Format_Grayscale8);

    m_img2show = m_img2show.scaled(ui->secondlphoto->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);

    m_pix2show=QPixmap::fromImage(m_img2show);

    ui->secondlphoto->setPixmap(m_pix2show);

    ui->PSNR->setText("PSNR: "+QString::number(Compress_gray::getPSNR(cg->img,result)));
}

