/*! ***********************************************************************************************
 *
 * \file        tywidget.cpp
 * \brief       ty 主窗口类源文件。
 *
 * \version     0.1
 * \date        2017/05/11
 *
 * \author      仇道林 <karoyqiu@gmail.com>
 * \copyright   © 2016 仇道林。
 * \license     MIT
 *
 **************************************************************************************************/
#include "stdafx.h"
#include "tywidget.h"
#include "ui_tywidget.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <Document.hpp>


TyWidget::TyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TyWidgetClass)
{
    ui->setupUi(this);
    connect(ui->buttonRun, &QPushButton::clicked, this, &TyWidget::run);
    QTimer::singleShot(1000, this, &TyWidget::run);
}


TyWidget::~TyWidget()
{
    delete ui;
}


void TyWidget::run()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QS("http://tieba.baidu.com/p/5110863154"));
    auto *reply = manager->get(request);
    
    do
    {
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec(QEventLoop::ExcludeUserInputEvents);
    } while (!reply->isFinished());

    auto doc = gq::Document::Create();

    try
    {
        std::string s;
        s.resize(reply->bytesAvailable());
        reply->read(&s[0], reply->bytesAvailable());
        reply->deleteLater();

        doc->Parse(s);
        auto nodes = doc->Find("div.d_post_content");
        qDebug() << nodes.GetNodeCount();

        for (size_t i = 0; i < nodes.GetNodeCount(); i++)
        {
            auto *node = nodes.GetNodeAt(i);
            
            QString s = QString::fromStdString(node->GetOwnText()).trimmed();

            if (!s.isEmpty())
            {
                qDebug() << s;
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        qCritical() << "EXCEPTION:" << e.what();
        return;
    }

    qDebug() << "Done.";
}
