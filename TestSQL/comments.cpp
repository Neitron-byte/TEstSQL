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

void comments::createTables(const QString & table)
{
    qDebug() << "create Table";
    QSqlQuery query;
    query.exec(QString("CREATE TABLE %1 (id INTEGER PRIMARY KEY AUTOINCREMENT,description VARCHAR(255));").arg(table));
    query.exec(QString("INSERT INTO %1 (description) VALUES ('ETEST comment');").arg(table));

}

void comments::addTable()
{
    qDebug() << "add Tables";
    m_listTable = m_db.tables();
    qDebug() << m_listTable.count();
//    foreach (QString table, m_listTable) {
//        qDebug() << table;

//    }

}



comments::comments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::comments)
{
    ui->setupUi(this);

    connectionDB();
    m_model = new QSqlTableModel(this, m_db);
    createTables("ETEST2");
    addTable();
    m_currentTable = "";

    foreach (QString table, m_table) {
        qDebug() << table;

    }
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
    //qDebug() << arg;
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
    qDebug() << ui->plainTextEdit_comments->toPlainText();
    query.exec(QString("INSERT INTO %1 (description) VALUES ('%2')").arg(m_currentTable).arg(ui->plainTextEdit_comments->toPlainText()));
    //query.exec(QString("INSERT INTO %1 (description) VALUES ('ETEST comment');").arg(table));
    ui->plainTextEdit_comments->clear();
    m_model->select();
}

