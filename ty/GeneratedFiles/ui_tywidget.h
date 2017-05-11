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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TyWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelTemplate;
    QLineEdit *editUrl;
    QLabel *labelFrom;
    QSpinBox *spinFrom;
    QLabel *labelTo;
    QSpinBox *spinTo;
    QLabel *labelSelector;
    QLineEdit *editSelector;
    QLabel *labelSave;
    QLineEdit *editFilename;
    QToolButton *buttonBrowse;
    QPushButton *buttonRun;

    void setupUi(QWidget *TyWidgetClass)
    {
        if (TyWidgetClass->objectName().isEmpty())
            TyWidgetClass->setObjectName(QStringLiteral("TyWidgetClass"));
        TyWidgetClass->resize(486, 173);
        verticalLayout = new QVBoxLayout(TyWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelTemplate = new QLabel(TyWidgetClass);
        labelTemplate->setObjectName(QStringLiteral("labelTemplate"));

        gridLayout->addWidget(labelTemplate, 0, 0, 1, 1);

        editUrl = new QLineEdit(TyWidgetClass);
        editUrl->setObjectName(QStringLiteral("editUrl"));

        gridLayout->addWidget(editUrl, 0, 1, 1, 1);

        labelFrom = new QLabel(TyWidgetClass);
        labelFrom->setObjectName(QStringLiteral("labelFrom"));

        gridLayout->addWidget(labelFrom, 1, 0, 1, 1);

        spinFrom = new QSpinBox(TyWidgetClass);
        spinFrom->setObjectName(QStringLiteral("spinFrom"));
        spinFrom->setMinimum(1);
        spinFrom->setMaximum(65535);

        gridLayout->addWidget(spinFrom, 1, 1, 1, 1);

        labelTo = new QLabel(TyWidgetClass);
        labelTo->setObjectName(QStringLiteral("labelTo"));

        gridLayout->addWidget(labelTo, 2, 0, 1, 1);

        spinTo = new QSpinBox(TyWidgetClass);
        spinTo->setObjectName(QStringLiteral("spinTo"));
        spinTo->setMinimum(1);
        spinTo->setMaximum(65535);

        gridLayout->addWidget(spinTo, 2, 1, 1, 1);

        labelSelector = new QLabel(TyWidgetClass);
        labelSelector->setObjectName(QStringLiteral("labelSelector"));

        gridLayout->addWidget(labelSelector, 3, 0, 1, 1);

        editSelector = new QLineEdit(TyWidgetClass);
        editSelector->setObjectName(QStringLiteral("editSelector"));
        editSelector->setText(QStringLiteral("div.tpc_content"));

        gridLayout->addWidget(editSelector, 3, 1, 1, 1);

        labelSave = new QLabel(TyWidgetClass);
        labelSave->setObjectName(QStringLiteral("labelSave"));

        gridLayout->addWidget(labelSave, 4, 0, 1, 1);

        editFilename = new QLineEdit(TyWidgetClass);
        editFilename->setObjectName(QStringLiteral("editFilename"));

        gridLayout->addWidget(editFilename, 4, 1, 1, 1);

        buttonBrowse = new QToolButton(TyWidgetClass);
        buttonBrowse->setObjectName(QStringLiteral("buttonBrowse"));

        gridLayout->addWidget(buttonBrowse, 4, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonRun = new QPushButton(TyWidgetClass);
        buttonRun->setObjectName(QStringLiteral("buttonRun"));

        verticalLayout->addWidget(buttonRun);

#ifndef QT_NO_SHORTCUT
        labelTemplate->setBuddy(editUrl);
        labelFrom->setBuddy(spinFrom);
        labelTo->setBuddy(spinTo);
        labelSelector->setBuddy(editSelector);
        labelSave->setBuddy(editFilename);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(editUrl, spinFrom);
        QWidget::setTabOrder(spinFrom, spinTo);
        QWidget::setTabOrder(spinTo, editSelector);
        QWidget::setTabOrder(editSelector, editFilename);
        QWidget::setTabOrder(editFilename, buttonBrowse);
        QWidget::setTabOrder(buttonBrowse, buttonRun);

        retranslateUi(TyWidgetClass);

        QMetaObject::connectSlotsByName(TyWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *TyWidgetClass)
    {
        labelTemplate->setText(QApplication::translate("TyWidgetClass", "&URL template:", Q_NULLPTR));
        labelFrom->setText(QApplication::translate("TyWidgetClass", "&From:", Q_NULLPTR));
        labelTo->setText(QApplication::translate("TyWidgetClass", "&To:", Q_NULLPTR));
        labelSelector->setText(QApplication::translate("TyWidgetClass", "CSS &selector:", Q_NULLPTR));
        labelSave->setText(QApplication::translate("TyWidgetClass", "Save as:", Q_NULLPTR));
        buttonBrowse->setText(QApplication::translate("TyWidgetClass", "...", Q_NULLPTR));
        buttonRun->setText(QApplication::translate("TyWidgetClass", "Run", Q_NULLPTR));
        Q_UNUSED(TyWidgetClass);
    } // retranslateUi

};

namespace Ui {
    class TyWidgetClass: public Ui_TyWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYWIDGET_H
