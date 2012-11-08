#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QFile"
#include "QTextStream"

#include <QtGui/QApplication>
#include <QtGui/QPushButton>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (this->objectName().isEmpty())
    {
        this->setObjectName(QString::fromUtf8("ToolsWindow"));
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

    QPushButton *button_toMainMenu = new QPushButton(ui->centralWidget);
    QPushButton *button_Save = new QPushButton(ui->centralWidget);
    button_toMainMenu->setObjectName("button_toMainMenu");
    button_Save->setObjectName("button_Save");
    button_toMainMenu->setGeometry(20, 310, 171, 41);
    button_Save->setGeometry(310, 310, 181, 41);
    button_toMainMenu->setText(QString::fromUtf8("Выход в главное меню"));
    button_Save->setText(QString::fromUtf8("Сохранить настройки"));

    connect(button_Save,SIGNAL(clicked()),this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
