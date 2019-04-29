/********************************************************************************
** Form generated from reading UI file 'SortingStation.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTINGSTATION_H
#define UI_SORTINGSTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortingStationClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QTextEdit *inputText;
    QPushButton *SolveButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QTextEdit *outputText;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SortingStationClass)
    {
        if (SortingStationClass->objectName().isEmpty())
            SortingStationClass->setObjectName(QStringLiteral("SortingStationClass"));
        SortingStationClass->resize(600, 400);
        centralWidget = new QWidget(SortingStationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        inputText = new QTextEdit(groupBox);
        inputText->setObjectName(QStringLiteral("inputText"));

        gridLayout_2->addWidget(inputText, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        SolveButton = new QPushButton(centralWidget);
        SolveButton->setObjectName(QStringLiteral("SolveButton"));
        SolveButton->setCheckable(false);
        SolveButton->setFlat(false);

        verticalLayout->addWidget(SolveButton);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        outputText = new QTextEdit(groupBox_2);
        outputText->setObjectName(QStringLiteral("outputText"));
        outputText->setReadOnly(true);

        gridLayout->addWidget(outputText, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        SortingStationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SortingStationClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        SortingStationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SortingStationClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SortingStationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SortingStationClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SortingStationClass->setStatusBar(statusBar);

        retranslateUi(SortingStationClass);

        SolveButton->setDefault(false);


        QMetaObject::connectSlotsByName(SortingStationClass);
    } // setupUi

    void retranslateUi(QMainWindow *SortingStationClass)
    {
        SortingStationClass->setWindowTitle(QApplication::translate("SortingStationClass", "SortingStation", 0));
        groupBox->setTitle(QApplication::translate("SortingStationClass", "\320\222\320\262\320\276\320\264", 0));
        SolveButton->setText(QApplication::translate("SortingStationClass", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0));
        groupBox_2->setTitle(QApplication::translate("SortingStationClass", "\320\222\321\213\320\262\320\276\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class SortingStationClass: public Ui_SortingStationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTINGSTATION_H
