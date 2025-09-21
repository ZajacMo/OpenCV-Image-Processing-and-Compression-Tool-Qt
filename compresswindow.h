#ifndef COMPRESSWINDOW_H
#define COMPRESSWINDOW_H

#include <QMainWindow>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QFileDialog>
#include<QMessageBox>
#include<QString>
#include<QTextEdit>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include <QAbstractButton>
#include "Compress_gray.h"


namespace Ui {
class CompressWindow;
}

class CompressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CompressWindow(QWidget *parent = nullptr);
    virtual void resizeEvent(QResizeEvent* event);/*选择图片的槽函数声明*/
    ~CompressWindow();

signals:
    void returnmain();/*发出回到主界面的信号*/
    void touncompress();/*发出去解压缩界面的信号*/
    void tohelp();/*发出回到帮助界面的信号*/

private slots:
    void on_runbtn_clicked();

    void on_savebtn_clicked();

    void on_colorfulphoto_clicked();

    void on_blackphoto_clicked();

    void on_choosebtn_clicked();

    void on_uncompressBtn_clicked();

private:
    Ui::CompressWindow *ui;
    QImage m_imgSrc;
    QImage m_img2show;
    QPixmap m_pix2show;
    QString strFileName;
    QString savePath;
    Compress_gray* cg;
    //允许误差
    double sigma = 10;
    //彩色1 灰度0
    int isColorful = 0;
};

#endif // COMPRESSWINDOW_H
