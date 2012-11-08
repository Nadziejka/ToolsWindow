#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QFile"
#include "QTextStream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (this->objectName().isEmpty())
    {
        this->setObjectName(QString::fromUtf8("GameWindow"));
    }
    this->resize(500, 375);

    QString str;
    QString fileName=":/Style.txt";
    QFile inputFile(fileName);
    QTextStream ts(&inputFile);
    if(!inputFile.open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    str=ts.readAll();
    inputFile.close();

    this->setStyleSheet(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
