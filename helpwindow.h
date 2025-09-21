#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>


namespace Ui {
class HelpWindow;
}

class HelpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

signals:
    void returnmain();/*发出回到主界面的信号*/
    void touncompress();/*发出去解压缩界面的信号*/
    void tocompress();/*发出去压缩界面的信号*/


private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
