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

    QLabel *label_Lang = new QLabel(ui->centralWidget);
    QLabel *label_Color = new QLabel(ui->centralWidget);
    QLabel *label_Topic = new QLabel(ui->centralWidget);
    QLabel *label_main = new QLabel(ui->centralWidget);

    label_Lang->setObjectName("label_Lang");
    label_Color->setObjectName("label_Color");
    label_Topic->setObjectName("label_Topic");
    label_main->setObjectName("label_main");


    label_Lang->setGeometry(QRect(100, 80, 91, 20));
    label_Lang->setText(QString::fromUtf8("Язык слов"));

    label_Color->setGeometry(QRect(105, 160, 71, 20));
    label_Color->setText(QString::fromUtf8("Цвет"));

    label_Topic->setGeometry(QRect(100, 240, 51, 21));
    label_Topic->setText(QString::fromUtf8("Тема"));

    label_main->setGeometry(QRect(190, 30, 121, 21));
    label_main->setText(QString::fromUtf8("Настройки"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
