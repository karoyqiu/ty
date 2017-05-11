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

#include <Parser.hpp>

#include "downloader.h"


TyWidget::TyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TyWidgetClass)
    , manager_(Q_NULLPTR)
    , current_(0)
    , file_(Q_NULLPTR)
    , stream_(Q_NULLPTR)
{
    ui->setupUi(this);

    manager_ = new QNetworkAccessManager(this);

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setHostName(QS("127.0.0.1"));
    proxy.setPort(1080);
    manager_->setProxy(proxy);

    connect(ui->buttonRun, &QPushButton::clicked, this, &TyWidget::run);
}


TyWidget::~TyWidget()
{
    delete ui;
}


void TyWidget::run()
{
    try
    {
        // http://xxxxxxx/read.php?tid=1008561&fpage=0&toread=&page=%1 ~248
        // div.tpc_content
        gq::Parser parser;
        auto selector = parser.CreateSelector(ui->editSelector->text().toStdString());

        Downloader *d = new Downloader(manager_, this);
        d->setSelector(selector);
        connect(d, &Downloader::finished, this, &TyWidget::handleContent);

        Q_ASSERT(file_ == Q_NULLPTR);
        file_ = new QFile(ui->editFilename->text(), this);
        file_->open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
        stream_ = new QTextStream(file_);

        current_ = ui->spinFrom->value();
        d->download(ui->editUrl->text().arg(current_));
    }
    catch (const std::exception &e)
    {
        qCritical() << e.what();
    }
}


void TyWidget::handleContent()
{
    Downloader *d = qobject_cast<Downloader *>(sender());
    Q_ASSERT(d);

    *stream_ << d->text() << endl;

    current_++;

    if (current_ <= ui->spinTo->value())
    {
        d->download(ui->editUrl->text().arg(current_));
    }
    else
    {
        delete stream_;
        delete file_;
        stream_ = Q_NULLPTR;
        file_ = Q_NULLPTR;

        d->deleteLater();
        
        QMessageBox::information(this, QString(), tr("Done."));
    }
}
