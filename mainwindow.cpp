#include "mainwindow.h"
#include <QString>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QTreeView>
#include <QSplitter>
#include <QSqlDatabase>
#include <QMessageBox>
#include "EJDetailWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QStringLiteral("Journey"));

    QStandardItemModel *pModel = new QStandardItemModel(2, 1, this);
    loadData(pModel);

    QTreeView *pTreeView = new QTreeView;
    pTreeView->setModel(pModel);

    QTableView *pTableView = new QTableView;
    pTableView->setModel(pModel);

    QVBoxLayout *pVLayout = new QVBoxLayout;
    pVLayout->addWidget(pTreeView);
    pVLayout->addWidget(pTableView);

    EJDetailWidget *pDetailWidget = new EJDetailWidget;
    QHBoxLayout *pHLayout = new QHBoxLayout;

    QWidget *pWidgetLeft = new QWidget;
    pWidgetLeft->setLayout(pVLayout);

    QSplitter *pSplitter = new QSplitter;
    pSplitter->setOrientation(Qt::Horizontal);
    pSplitter->addWidget(pWidgetLeft);
    pSplitter->addWidget(pDetailWidget);
    pSplitter->setStretchFactor(0, 1);
    pSplitter->setStretchFactor(1, 4);
    pHLayout->addWidget(pSplitter);

    QWidget *pWidget = new QWidget;
    pWidget->setLayout(pHLayout);
    setCentralWidget(pWidget);

    resize(500, 300);
}

MainWindow::~MainWindow()
{

}

void MainWindow::loadData(QStandardItemModel *pModel)
{
    QStandardItem *pItem1 = new QStandardItem("test1");
    pItem1->setCheckState(Qt::Unchecked);
    pItem1->setCheckable(true);
    QStandardItem *pItem2 = new QStandardItem("test2");
    pItem2->setCheckState(Qt::Unchecked);
    pItem2->setCheckable(true);
    pModel->setItem(0, 0, pItem1);
    pModel->setItem(1, 0, pItem2);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1"); //连接本地主机
    db.setPort(3306);
    db.setDatabaseName("ej_db");
    db.setUserName("root@localhost");
    db.setPassword("123qwe!@#");
    if(db.open())
    {
        QMessageBox::information(this, "info", "Link success!");
    }
    else
    {
        QMessageBox::information(this, "info", "Link failed!");
    }
}
