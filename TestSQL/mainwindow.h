#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "comments.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBox_dev_currentIndexChanged(const QString &arg1);

signals:
    //void signal_change_table(const QString &);


private:
    Ui::MainWindow *ui;

    comments* m_comments = nullptr;


};
#endif // MAINWINDOW_H
