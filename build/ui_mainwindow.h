/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *inputbutton;
    QPushButton *exitbutton;
    QLabel *logolabel;
    QLabel *handzonelabel;
    QLabel *humanlabel;
    QLabel *humanequiplabel;
    QLabel *rebelwinlabel;
    QLabel *lordwinlabel;
    QLabel *renegadewinlabel;
    QLabel *tiplabel;
    QPushButton *helpbutton;
    QPushButton *autoplaybutton;
    QPushButton *cancelautobutton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1600, 1000);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 320, 114, 32));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 10, 114, 32));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        inputbutton = new QPushButton(centralWidget);
        inputbutton->setObjectName(QStringLiteral("inputbutton"));
        inputbutton->setGeometry(QRect(390, 270, 114, 32));
        exitbutton = new QPushButton(centralWidget);
        exitbutton->setObjectName(QStringLiteral("exitbutton"));
        exitbutton->setGeometry(QRect(550, 150, 114, 32));
        exitbutton->setCursor(QCursor(Qt::PointingHandCursor));
        logolabel = new QLabel(centralWidget);
        logolabel->setObjectName(QStringLiteral("logolabel"));
        logolabel->setGeometry(QRect(260, 40, 271, 111));
        handzonelabel = new QLabel(centralWidget);
        handzonelabel->setObjectName(QStringLiteral("handzonelabel"));
        handzonelabel->setGeometry(QRect(110, 160, 62, 16));
        humanlabel = new QLabel(centralWidget);
        humanlabel->setObjectName(QStringLiteral("humanlabel"));
        humanlabel->setGeometry(QRect(90, 120, 62, 16));
        humanequiplabel = new QLabel(centralWidget);
        humanequiplabel->setObjectName(QStringLiteral("humanequiplabel"));
        humanequiplabel->setGeometry(QRect(140, 110, 62, 16));
        rebelwinlabel = new QLabel(centralWidget);
        rebelwinlabel->setObjectName(QStringLiteral("rebelwinlabel"));
        rebelwinlabel->setGeometry(QRect(80, 150, 501, 261));
        QFont font;
        font.setFamily(QString::fromUtf8("\350\241\214\346\245\267-\347\256\200"));
        font.setPointSize(200);
        rebelwinlabel->setFont(font);
        lordwinlabel = new QLabel(centralWidget);
        lordwinlabel->setObjectName(QStringLiteral("lordwinlabel"));
        lordwinlabel->setGeometry(QRect(90, 20, 501, 261));
        lordwinlabel->setFont(font);
        renegadewinlabel = new QLabel(centralWidget);
        renegadewinlabel->setObjectName(QStringLiteral("renegadewinlabel"));
        renegadewinlabel->setGeometry(QRect(80, 270, 501, 261));
        renegadewinlabel->setFont(font);
        tiplabel = new QLabel(centralWidget);
        tiplabel->setObjectName(QStringLiteral("tiplabel"));
        tiplabel->setGeometry(QRect(180, 10, 291, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\277\251\347\277\251\344\275\223-\347\256\200"));
        font1.setPointSize(18);
        tiplabel->setFont(font1);
        tiplabel->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"\n"
""));
        tiplabel->setFrameShape(QFrame::NoFrame);
        tiplabel->setFrameShadow(QFrame::Sunken);
        helpbutton = new QPushButton(centralWidget);
        helpbutton->setObjectName(QStringLiteral("helpbutton"));
        helpbutton->setGeometry(QRect(10, 40, 114, 32));
        autoplaybutton = new QPushButton(centralWidget);
        autoplaybutton->setObjectName(QStringLiteral("autoplaybutton"));
        autoplaybutton->setGeometry(QRect(10, 90, 114, 32));
        autoplaybutton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelautobutton = new QPushButton(centralWidget);
        cancelautobutton->setObjectName(QStringLiteral("cancelautobutton"));
        cancelautobutton->setGeometry(QRect(10, 130, 114, 32));
        cancelautobutton->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Show Input ", 0));
        pushButton_2->setText(QString());
        inputbutton->setText(QApplication::translate("MainWindow", "Input", 0));
        exitbutton->setText(QString());
        logolabel->setText(QString());
        handzonelabel->setText(QString());
        humanlabel->setText(QString());
        humanequiplabel->setText(QString());
        rebelwinlabel->setText(QApplication::translate("MainWindow", "\345\217\215\350\264\274\350\216\267\350\203\234", 0));
        lordwinlabel->setText(QApplication::translate("MainWindow", "\344\270\273\345\205\254\350\216\267\350\203\234", 0));
        renegadewinlabel->setText(QApplication::translate("MainWindow", "\345\206\205\345\245\270\350\216\267\350\203\234", 0));
        tiplabel->setText(QApplication::translate("MainWindow", "\350\257\267\345\234\250\346\255\244\351\200\211\346\213\251\346\223\215\344\275\234,\345\271\266\346\214\211Enter\351\224\256\350\276\223\345\205\245-->", 0));
        helpbutton->setText(QString());
        autoplaybutton->setText(QString());
        cancelautobutton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
