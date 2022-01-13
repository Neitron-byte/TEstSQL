#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_comments(new comments)

{
    ui->setupUi(this);

    ui->verticalLayout_comm->addWidget(m_comments);

    //connect(this,SIGNAL(signal_change_table(const QString &)),m_comments,SLOT(slotSetTable(const QString &)));

    ui->comboBox_dev->addItems(m_comments->getTableList());
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_comboBox_dev_currentIndexChanged(const QString &arg1)
{
    if (arg1 != "  "){
        m_comments->setCurrentTable(arg1);
        //emit signal_change_table(arg1);
    }

}
