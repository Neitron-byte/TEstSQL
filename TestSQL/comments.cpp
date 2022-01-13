#include "comments.h"
#include "ui_comments.h"
#include "QMessageBox"
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRecord>
#include <QDebug>
#include <QString>

void comments::connectionDB()
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

void comments::createTables()
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

void comments::addTable()
{
    qDebug() << "add Tables";
    m_listTable = m_db.tables();
    qDebug() << m_listTable.count();
    foreach (QString table, m_listTable) {
        qDebug() << table;

    }

}



comments::comments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comments)
{
    ui->setupUi(this);

    connectionDB();
    m_model = new QSqlTableModel(this, m_db);
    createTables();
    addTable();
    m_currentTable = "";
}

comments::~comments()
{
    delete ui;
    delete m_model;

}

QStringList &comments::getTableList()
{
    return m_listTable;
}

void comments::setCurrentTable(const QString & arg)
{
    qDebug() << arg;
    m_currentTable = arg;
    m_model->setTable(arg);
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

    ui->listView_comm->setModel(m_model);
    ui->listView_comm->setModelColumn(1);
}


void comments::on_pushButton_add_comm_clicked()
{
    QString comm = ui->plainTextEdit_comments->toPlainText();
    QSqlQuery query;
    query.exec("CREATE TABLE %1 (id INT PRIMARY KEY, comments VARCHAR(100))".arg(m_currentTable));
    showStatusMessage(tr("Подключено к %1 : %2, %3, %4, %5, %6")
                      .arg(m_serial->portName()).arg(m_serial->baudRate()).arg(m_serial->dataBits())
                      .arg(m_serial->parity()).arg(m_serial->stopBits()).arg(m_serial->flowControl()));

    query.exec("INSERT INTO E1 (id,comments) VALUES (1,'E1 First comment'),(2, 'E1 Second Comments'),(3, 'E1 Three comments')");
}

