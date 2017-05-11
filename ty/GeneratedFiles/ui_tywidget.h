/********************************************************************************
** Form generated from reading UI file 'tywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYWIDGET_H
#define UI_TYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TyWidgetClass
{
public:

    void setupUi(QWidget *TyWidgetClass)
    {
        if (TyWidgetClass->objectName().isEmpty())
            TyWidgetClass->setObjectName(QStringLiteral("TyWidgetClass"));
        TyWidgetClass->resize(600, 400);

        retranslateUi(TyWidgetClass);

        QMetaObject::connectSlotsByName(TyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TyWidgetClass)
    {
        TyWidgetClass->setWindowTitle(QApplication::translate("TyWidgetClass", "TyWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TyWidgetClass: public Ui_TyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYWIDGET_H
