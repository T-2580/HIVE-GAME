/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGraphicsView *graphicsView;
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        graphicsView = new QGraphicsView(Dialog);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 20, 270, 200));
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 230, 120, 30));
        widget_2 = new QWidget(Dialog);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(310, 20, 40, 200));
        pushButton_1 = new QPushButton(widget_2);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(0, 0, 35, 24));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../images/pieces/1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_1->setIcon(icon);
        pushButton_1->setIconSize(QSize(8, 8));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 30, 35, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../images/pieces/2.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(8, 8));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 60, 35, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../images/pieces/3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(8, 8));
        pushButton_4 = new QPushButton(widget_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 90, 35, 24));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../images/pieces/4.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(8, 8));
        pushButton_5 = new QPushButton(widget_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 120, 35, 24));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../images/pieces/5.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon4);
        pushButton_5->setIconSize(QSize(8, 8));
        widget_3 = new QWidget(Dialog);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(350, 20, 40, 200));
        pushButton_6 = new QPushButton(widget_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 0, 35, 24));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../images/pieces/6.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(8, 8));
        pushButton_7 = new QPushButton(widget_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 30, 35, 24));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../images/pieces/7.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon6);
        pushButton_7->setIconSize(QSize(8, 8));
        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 60, 35, 24));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../images/pieces/8.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon7);
        pushButton_8->setIconSize(QSize(8, 8));
        pushButton_9 = new QPushButton(widget_3);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(0, 90, 35, 24));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../images/pieces/9.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_9->setIcon(icon8);
        pushButton_9->setIconSize(QSize(8, 8));
        pushButton_10 = new QPushButton(widget_3);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(0, 120, 35, 24));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../images/pieces/10.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_10->setIcon(icon9);
        pushButton_10->setIconSize(QSize(8, 8));
        widget_3->raise();
        graphicsView->raise();
        widget->raise();
        widget_2->raise();

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        pushButton_1->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Dialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
