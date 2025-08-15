/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *controlCenterButton;
    QPushButton *fireFightersButton;
    QPushButton *dotButton;
    QPushButton *enpButton;
    QPushButton *ambulanceButton;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addEmergencyButton;
    QPushButton *removeEmergencyButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        controlCenterButton = new QPushButton(centralwidget);
        controlCenterButton->setObjectName("controlCenterButton");

        horizontalLayout->addWidget(controlCenterButton);

        fireFightersButton = new QPushButton(centralwidget);
        fireFightersButton->setObjectName("fireFightersButton");

        horizontalLayout->addWidget(fireFightersButton);

        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName("dotButton");

        horizontalLayout->addWidget(dotButton);

        enpButton = new QPushButton(centralwidget);
        enpButton->setObjectName("enpButton");

        horizontalLayout->addWidget(enpButton);

        ambulanceButton = new QPushButton(centralwidget);
        ambulanceButton->setObjectName("ambulanceButton");

        horizontalLayout->addWidget(ambulanceButton);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        addEmergencyButton = new QPushButton(centralwidget);
        addEmergencyButton->setObjectName("addEmergencyButton");

        horizontalLayout_2->addWidget(addEmergencyButton);

        removeEmergencyButton = new QPushButton(centralwidget);
        removeEmergencyButton->setObjectName("removeEmergencyButton");

        horizontalLayout_2->addWidget(removeEmergencyButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Emergency Call Control Center", nullptr));
        controlCenterButton->setText(QCoreApplication::translate("MainWindow", "Control Center", nullptr));
        fireFightersButton->setText(QCoreApplication::translate("MainWindow", "Fire Fighters", nullptr));
        dotButton->setText(QCoreApplication::translate("MainWindow", "DOT", nullptr));
        enpButton->setText(QCoreApplication::translate("MainWindow", "ENP", nullptr));
        ambulanceButton->setText(QCoreApplication::translate("MainWindow", "Ambulance", nullptr));
        addEmergencyButton->setText(QCoreApplication::translate("MainWindow", "Add Emergency", nullptr));
        removeEmergencyButton->setText(QCoreApplication::translate("MainWindow", "Remove Emergency", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
