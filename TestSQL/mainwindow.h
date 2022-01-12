#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSQLDatabase>
#include <QStringList>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void connectionDB();
    void createTables();
    void addTable();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void on_comboBox_dev_currentIndexChanged(int index);

    void on_comboBox_dev_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_db;
    QStringList m_listTable;
    QSqlTableModel* m_model;

};
#endif // MAINWINDOW_H
