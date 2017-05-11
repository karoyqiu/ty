/*! ***********************************************************************************************
 *
 * \file        main.cpp
 * \brief       ty 主源文件。
 *
 * \version     0.1
 * \date        2017/05/11
 *
 * \author      仇道林 <karoyqiu@gmail.com>
 * \copyright   © 2016 仇道林。
 *
 **************************************************************************************************/
#include "stdafx.h"

#include <QApplication>

#include "tywidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName(QS("ty"));
    QApplication::setApplicationDisplayName(QS("Ty"));
    QApplication::setOrganizationName(QS("karoyqiu"));

    TyWidget w;
    w.show();

    return a.exec();
}
