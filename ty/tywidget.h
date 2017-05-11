/*! ***********************************************************************************************
 *
 * \file        tywidget.h
 * \brief       ty 主窗口类头文件。
 *
 * \version     0.1
 * \date        2017/05/11
 *
 * \author      仇道林 <karoyqiu@gmail.com>
 * \copyright   © 2016 仇道林。
 * \license     MIT
 *
 **************************************************************************************************/
#pragma once
#include <QWidget>

#include "ui_tywidget.h"


class TyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TyWidget(QWidget *parent = Q_NULLPTR);

private:
    Ui::TyWidgetClass ui;
};
