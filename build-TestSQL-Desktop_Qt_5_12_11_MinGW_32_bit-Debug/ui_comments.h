/********************************************************************************
** Form generated from reading UI file 'comments.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTS_H
#define UI_COMMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_comments
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *listView_comm;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *plainTextEdit_comments;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_add_comm;

    void setupUi(QWidget *comments)
    {
        if (comments->objectName().isEmpty())
            comments->setObjectName(QString::fromUtf8("comments"));
        comments->resize(299, 428);
        verticalLayout = new QVBoxLayout(comments);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(comments);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        listView_comm = new QListView(comments);
        listView_comm->setObjectName(QString::fromUtf8("listView_comm"));
        listView_comm->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(listView_comm);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        plainTextEdit_comments = new QPlainTextEdit(comments);
        plainTextEdit_comments->setObjectName(QString::fromUtf8("plainTextEdit_comments"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_comments->sizePolicy().hasHeightForWidth());
        plainTextEdit_comments->setSizePolicy(sizePolicy);
        plainTextEdit_comments->setMinimumSize(QSize(200, 100));
        plainTextEdit_comments->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(plainTextEdit_comments);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_add_comm = new QPushButton(comments);
        pushButton_add_comm->setObjectName(QString::fromUtf8("pushButton_add_comm"));

        horizontalLayout->addWidget(pushButton_add_comm);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(comments);

        QMetaObject::connectSlotsByName(comments);
    } // setupUi

    void retranslateUi(QWidget *comments)
    {
        comments->setWindowTitle(QApplication::translate("comments", "Form", nullptr));
        label->setText(QApplication::translate("comments", "\320\232\320\276\320\274\320\274\320\265\320\275\321\202\320\260\321\200\320\270\320\270/\320\237\320\276\321\217\321\201\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_add_comm->setText(QApplication::translate("comments", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class comments: public Ui_comments {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTS_H
