#include <QtDebug>
#include <QAction>
#include <QDir>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"graphicsviewer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectEvents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectEvents()
{
    connect(ui->viewBtn,&QPushButton::clicked, this, [this]{ onViewBtnClicked();});
    connect(ui->browseBtn,&QPushButton::clicked, this, [this]{ onBrowseBtnClicked();});
}

void MainWindow::onBrowseBtnClicked()
{
    qDebug() << "onBrowseBtnClicked";
    QString directory = QFileDialog::getOpenFileName(this, tr("Open file"), "", NULL);
    QFileInfo  fileInfo(directory);
    if (directory.isEmpty() || !fileInfo.exists()) {
        return;
    }
    ui->filePathLineEdit->setText(directory);
    qDebug() <<directory;
}

void MainWindow::onViewBtnClicked()
{
    qDebug() << "onViewBtnClicked";
    QString filePath = ui->filePathLineEdit->text();
    QFileInfo  fileInfo(filePath);

    if(filePath.isEmpty() || !fileInfo.exists()){
        return;
    }

    GraphicsViewer* graphicsViewer = new GraphicsViewer(nullptr, filePath);
    graphicsViewer->show();

}
