#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRecord>

void MainWindow::connectionDB()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("errors");
    if (!m_db.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);

    } else {
        qDebug() << "m_db is open";
    }

}

void MainWindow::createTables()
{
    qDebug() << "create Table";
    QSqlQuery query;
    query.exec("CREATE TABLE E1 (id INT PRIMARY KEY, comments VARCHAR(100))");
    query.exec("INSERT INTO E1 (id,comments) VALUES (1,'E1 First comment'),(2, 'E1 Second Comments'),(3, 'E1 Three comments')");

    query.exec("CREATE TABLE E2 (id INT PRIMARY KEY, comments VARCHAR(100))");
    query.exec("INSERT INTO E2 (id, comments) VALUES (1, 'E2 First comment'),(2, 'E2 Second Comments'),(3, 'E2 Three comments')");

    query.exec("CREATE TABLE E3 (id INT PRIMARY KEY, comments VARCHAR(100))");
    query.exec("INSERT INTO E3 (id, comments) VALUES (1, 'E3 First comment'),(2, 'E3 Second Comments'),(3, 'E3 Three comments')");


}

void MainWindow::addTable()
{
    qDebug() << "add Tables";
    m_listTable = m_db.tables();
    qDebug() << m_listTable.count();
    foreach (QString table, m_listTable) {
        qDebug() << table;

    }
    ui->comboBox_dev->addItem("  ");
    ui->comboBox_dev->addItems(m_listTable);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    ui->comboBox_dev->addItem("E1");
//    ui->comboBox_dev->addItem("E2");
//    ui->comboBox_dev->addItem("E3");

    connectionDB();
    m_model = new QSqlTableModel(this, m_db);
    createTables();
    addTable();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_model;
}


//void MainWindow::on_comboBox_dev_currentIndexChanged(int index)
//{
//    switch (index) {
//    case 0:

//        break;
//    default:
//        break;
//    }
//}

void MainWindow::on_comboBox_dev_currentIndexChanged(const QString &arg1)
{
    if (arg1 != "  "){
        qDebug() << arg1;
        m_model->setTable(arg1);
        m_model->select();
        //model.setEditStrategy(QSqlTableModel::OnManualSubmit);

        qDebug() << m_model->rowCount();

        for (int nRow = 0; nRow <  m_model->rowCount(); ++nRow) {
        QSqlRecord rec =  m_model->record(nRow);
        int nNumber = rec.value("id").toInt();
        qDebug() << nNumber;
        QString strName = rec.value ( "comments").toString();
        qDebug() << strName;
        }
        //model.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        //model.setHeaderData(1, Qt::Horizontal, QObject::tr("Comments"));

        ui->tableView_comments->setModel(m_model);
    }
    //ui->tableView_comments->show();
}
