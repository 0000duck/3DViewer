#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void connectEvents();
    void onBrowseBtnClicked();
    void onViewBtnClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
