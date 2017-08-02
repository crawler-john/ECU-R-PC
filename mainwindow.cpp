#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug.h"
#include "Source/socket/Socket.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_config_clicked()
{
    testSocket();
}
