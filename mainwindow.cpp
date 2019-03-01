#include <QtDebug>
#include <QAction>
#include <QDir>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if (!directory.isEmpty()) {
        ui->filePathLineEdit->insert(directory);
        qDebug() <<directory;
    }
}

void MainWindow::onViewBtnClicked()
{
    qDebug() << "onViewBtnClicked";
    QString filePath = ui->filePathLineEdit->text();
}
