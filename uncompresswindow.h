#ifndef UNCOMPRESSWINDOW_H
#define UNCOMPRESSWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QTextStream>
#include<QFileDialog>
#include "Compress_gray.h"

namespace Ui {
class uncompressWindow;
}

class uncompressWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit uncompressWindow(QWidget *parent = nullptr);
    void choose();/*选择文档打开的槽函数*/
    ~uncompressWindow();

signals:
    void returnmain();/*发出回到主界面的信号*/
    void tohelp();/*发出回到帮助界面的信号*/
    void tocompress();/*发出去压缩界面的信号*/

private slots:
    void on_choosebtn_clicked();

    void on_savebtn_clicked();

    void on_runbtn_clicked();

private:
    Ui::uncompressWindow *ui;
    Compress_gray* ucg;
    QString fileName;
};

#endif // UNCOMPRESSWINDOW_H
