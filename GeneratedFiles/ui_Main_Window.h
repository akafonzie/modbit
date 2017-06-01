/********************************************************************************
** Form generated from reading UI file 'Main_Window.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MAIN_WINDOWClass
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionMaximise;
    QAction *actionMinimise;
    QAction *actionExit;
    QAction *actionExit_2;
    QAction *actionFullscreen;
    QAction *actionExit_3;
    QAction *actionNew;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MAIN_WINDOWClass)
    {
        if (MAIN_WINDOWClass->objectName().isEmpty())
            MAIN_WINDOWClass->setObjectName(QStringLiteral("MAIN_WINDOWClass"));
        MAIN_WINDOWClass->resize(695, 563);
        actionLoad = new QAction(MAIN_WINDOWClass);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MAIN_WINDOWClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionUndo = new QAction(MAIN_WINDOWClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(MAIN_WINDOWClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionMaximise = new QAction(MAIN_WINDOWClass);
        actionMaximise->setObjectName(QStringLiteral("actionMaximise"));
        actionMinimise = new QAction(MAIN_WINDOWClass);
        actionMinimise->setObjectName(QStringLiteral("actionMinimise"));
        actionExit = new QAction(MAIN_WINDOWClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit_2 = new QAction(MAIN_WINDOWClass);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        actionFullscreen = new QAction(MAIN_WINDOWClass);
        actionFullscreen->setObjectName(QStringLiteral("actionFullscreen"));
        actionExit_3 = new QAction(MAIN_WINDOWClass);
        actionExit_3->setObjectName(QStringLiteral("actionExit_3"));
        actionNew = new QAction(MAIN_WINDOWClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        centralWidget = new QWidget(MAIN_WINDOWClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MAIN_WINDOWClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MAIN_WINDOWClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 695, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        MAIN_WINDOWClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MAIN_WINDOWClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MAIN_WINDOWClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MAIN_WINDOWClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MAIN_WINDOWClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuWindow->addAction(actionMaximise);
        menuWindow->addAction(actionMinimise);
        menuWindow->addAction(actionFullscreen);
        menuWindow->addAction(actionExit_3);

        retranslateUi(MAIN_WINDOWClass);
        QObject::connect(actionMaximise, SIGNAL(triggered()), MAIN_WINDOWClass, SLOT(showMaximized()));
        QObject::connect(actionMinimise, SIGNAL(triggered()), MAIN_WINDOWClass, SLOT(showMinimized()));
        QObject::connect(actionFullscreen, SIGNAL(triggered()), MAIN_WINDOWClass, SLOT(showFullScreen()));
        QObject::connect(actionExit_3, SIGNAL(triggered()), MAIN_WINDOWClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MAIN_WINDOWClass);
    } // setupUi

    void retranslateUi(QMainWindow *MAIN_WINDOWClass)
    {
        MAIN_WINDOWClass->setWindowTitle(QApplication::translate("MAIN_WINDOWClass", "MAIN_WINDOW", 0));
        actionLoad->setText(QApplication::translate("MAIN_WINDOWClass", "Load", 0));
        actionSave->setText(QApplication::translate("MAIN_WINDOWClass", "Save", 0));
        actionUndo->setText(QApplication::translate("MAIN_WINDOWClass", "Undo", 0));
        actionRedo->setText(QApplication::translate("MAIN_WINDOWClass", "Redo", 0));
        actionMaximise->setText(QApplication::translate("MAIN_WINDOWClass", "Maximise", 0));
        actionMinimise->setText(QApplication::translate("MAIN_WINDOWClass", "Minimise", 0));
        actionExit->setText(QApplication::translate("MAIN_WINDOWClass", "Exit", 0));
        actionExit_2->setText(QApplication::translate("MAIN_WINDOWClass", "Exit", 0));
        actionFullscreen->setText(QApplication::translate("MAIN_WINDOWClass", "Fullscreen", 0));
        actionExit_3->setText(QApplication::translate("MAIN_WINDOWClass", "Exit", 0));
        actionNew->setText(QApplication::translate("MAIN_WINDOWClass", "New", 0));
        menuFile->setTitle(QApplication::translate("MAIN_WINDOWClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("MAIN_WINDOWClass", "Edit", 0));
        menuWindow->setTitle(QApplication::translate("MAIN_WINDOWClass", "Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MAIN_WINDOWClass: public Ui_MAIN_WINDOWClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
