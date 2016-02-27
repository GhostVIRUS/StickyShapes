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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SSMainWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SSMainWindowClass)
    {
        if (SSMainWindowClass->objectName().isEmpty())
            SSMainWindowClass->setObjectName(QStringLiteral("SSMainWindowClass"));
        SSMainWindowClass->resize(600, 400);
        SSMainWindowClass->setMinimumSize(QSize(600, 400));
        SSMainWindowClass->setMaximumSize(QSize(800, 600));
        SSMainWindowClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        SSMainWindowClass->setDocumentMode(false);
        SSMainWindowClass->setTabShape(QTabWidget::Rounded);
        SSMainWindowClass->setDockNestingEnabled(false);
        centralWidget = new QWidget(SSMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMaximumSize(QSize(800, 600));

        horizontalLayout->addWidget(graphicsView);

        SSMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SSMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        SSMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SSMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SSMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SSMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SSMainWindowClass->setStatusBar(statusBar);

        retranslateUi(SSMainWindowClass);

        QMetaObject::connectSlotsByName(SSMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SSMainWindowClass)
    {
        SSMainWindowClass->setWindowTitle(QApplication::translate("SSMainWindowClass", "Sticky Shapes", 0));
    } // retranslateUi

};

namespace Ui {
    class SSMainWindowClass: public Ui_SSMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSMAINWINDOW_H
