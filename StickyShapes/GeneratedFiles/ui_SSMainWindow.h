/********************************************************************************
** Form generated from reading UI file 'SSMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSMAINWINDOW_H
#define UI_SSMAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "Scene.h"

QT_BEGIN_NAMESPACE

class Ui_SSMainWindowClass
{
public:
    QAction *actionClearScene;
    QAction *actionAddShape;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    Scene *scene;
    QHBoxLayout *horizontalLayout_2;
    QMenuBar *menuBar;
    QMenu *menuScene;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SSMainWindowClass)
    {
        if (SSMainWindowClass->objectName().isEmpty())
            SSMainWindowClass->setObjectName(QStringLiteral("SSMainWindowClass"));
        SSMainWindowClass->resize(600, 400);
        SSMainWindowClass->setMinimumSize(QSize(600, 400));
        SSMainWindowClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        SSMainWindowClass->setDocumentMode(false);
        SSMainWindowClass->setTabShape(QTabWidget::Rounded);
        SSMainWindowClass->setDockNestingEnabled(false);
        actionClearScene = new QAction(SSMainWindowClass);
        actionClearScene->setObjectName(QStringLiteral("actionClearScene"));
        actionAddShape = new QAction(SSMainWindowClass);
        actionAddShape->setObjectName(QStringLiteral("actionAddShape"));
        centralWidget = new QWidget(SSMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scene = new Scene(centralWidget);
        scene->setObjectName(QStringLiteral("scene"));
        horizontalLayout_2 = new QHBoxLayout(scene);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        horizontalLayout->addWidget(scene);

        SSMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SSMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuScene = new QMenu(menuBar);
        menuScene->setObjectName(QStringLiteral("menuScene"));
        SSMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SSMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SSMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SSMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SSMainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuScene->menuAction());
        menuScene->addAction(actionClearScene);
        menuScene->addAction(actionAddShape);

        retranslateUi(SSMainWindowClass);
        QObject::connect(actionAddShape, SIGNAL(triggered()), SSMainWindowClass, SLOT(slotAddShape()));
        QObject::connect(actionClearScene, SIGNAL(triggered()), SSMainWindowClass, SLOT(slotClearScene()));

        QMetaObject::connectSlotsByName(SSMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SSMainWindowClass)
    {
        SSMainWindowClass->setWindowTitle(QApplication::translate("SSMainWindowClass", "Sticky Shapes", 0));
        actionClearScene->setText(QApplication::translate("SSMainWindowClass", "Clear Scene", 0));
        actionClearScene->setShortcut(QApplication::translate("SSMainWindowClass", "Ctrl+C", 0));
        actionAddShape->setText(QApplication::translate("SSMainWindowClass", "Add Shape", 0));
        actionAddShape->setShortcut(QApplication::translate("SSMainWindowClass", "Ctrl+A", 0));
        menuScene->setTitle(QApplication::translate("SSMainWindowClass", "Scene", 0));
    } // retranslateUi

};

namespace Ui {
    class SSMainWindowClass: public Ui_SSMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSMAINWINDOW_H
