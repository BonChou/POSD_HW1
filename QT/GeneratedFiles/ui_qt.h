/********************************************************************************
** Form generated from reading UI file 'qt.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_H
#define UI_QT_H

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

class Ui_QTClass
{
public:
    QAction *actionCreate_a_new_mind_map;
    QAction *actionOpen_a_mind_map;
    QAction *actionLoad_a_mind_map;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionInsert_a_Child;
    QAction *actionInsert_a_Sibling;
    QAction *actionInsert_a_Parent;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *QTClass)
    {
        if (QTClass->objectName().isEmpty())
            QTClass->setObjectName(QStringLiteral("QTClass"));
        QTClass->resize(681, 400);
        actionCreate_a_new_mind_map = new QAction(QTClass);
        actionCreate_a_new_mind_map->setObjectName(QStringLiteral("actionCreate_a_new_mind_map"));
        QIcon icon;
        icon.addFile(QStringLiteral("EditIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_a_new_mind_map->setIcon(icon);
        QFont font;
        font.setUnderline(false);
        actionCreate_a_new_mind_map->setFont(font);
        actionOpen_a_mind_map = new QAction(QTClass);
        actionOpen_a_mind_map->setObjectName(QStringLiteral("actionOpen_a_mind_map"));
        actionLoad_a_mind_map = new QAction(QTClass);
        actionLoad_a_mind_map->setObjectName(QStringLiteral("actionLoad_a_mind_map"));
        actionEdit = new QAction(QTClass);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionDelete = new QAction(QTClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionInsert_a_Child = new QAction(QTClass);
        actionInsert_a_Child->setObjectName(QStringLiteral("actionInsert_a_Child"));
        actionInsert_a_Sibling = new QAction(QTClass);
        actionInsert_a_Sibling->setObjectName(QStringLiteral("actionInsert_a_Sibling"));
        actionInsert_a_Parent = new QAction(QTClass);
        actionInsert_a_Parent->setObjectName(QStringLiteral("actionInsert_a_Parent"));
        centralWidget = new QWidget(QTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QTClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 681, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setFont(font);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QTClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QTClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTClass->setStatusBar(statusBar);
        mainToolBar = new QToolBar(QTClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCreate_a_new_mind_map);
        menuFile->addAction(actionOpen_a_mind_map);
        menuFile->addAction(actionLoad_a_mind_map);
        menuEdit->addAction(actionEdit);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionInsert_a_Child);
        menuEdit->addAction(actionInsert_a_Sibling);
        menuEdit->addAction(actionInsert_a_Parent);

        retranslateUi(QTClass);

        QMetaObject::connectSlotsByName(QTClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTClass)
    {
        QTClass->setWindowTitle(QApplication::translate("QTClass", "QT", 0));
        actionCreate_a_new_mind_map->setText(QApplication::translate("QTClass", "Create a new mind map\n"
"", 0));
        actionOpen_a_mind_map->setText(QApplication::translate("QTClass", "Save a mind map", 0));
        actionLoad_a_mind_map->setText(QApplication::translate("QTClass", "Load a mind map", 0));
        actionEdit->setText(QApplication::translate("QTClass", "Edit", 0));
        actionDelete->setText(QApplication::translate("QTClass", "Delete", 0));
        actionInsert_a_Child->setText(QApplication::translate("QTClass", "Insert a Child", 0));
        actionInsert_a_Sibling->setText(QApplication::translate("QTClass", "Insert a Sibling", 0));
        actionInsert_a_Parent->setText(QApplication::translate("QTClass", "Insert a Parent", 0));
        menuFile->setTitle(QApplication::translate("QTClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("QTClass", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("QTClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class QTClass: public Ui_QTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_H
