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

#include <Parser.hpp>

#include "downloader.h"


TyWidget::TyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TyWidgetClass)
    , manager_(Q_NULLPTR)
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

    connect(ui->buttonBrowse, &QPushButton::clicked, this, &TyWidget::browse);
    connect(ui->buttonRun, &QPushButton::clicked, this, &TyWidget::run);
}


TyWidget::~TyWidget()
{
    delete ui;
}


void TyWidget::browse()
{
    auto filename = QFileDialog::getSaveFileName(this, QString(), QString(), tr("Text files (*.txt)"));

    if (!filename.isEmpty())
    {
        ui->editFilename->setText(QDir::toNativeSeparators(filename));
    }
}


void TyWidget::run()
{
    try
    {
        enableUI(false);

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

        ui->progressBar->setRange(ui->spinFrom->value(), ui->spinTo->value());
        ui->progressBar->setValue(ui->spinFrom->value());
        qInfo() << "Downloading page" << ui->progressBar->value();
        d->download(ui->editUrl->text().arg(ui->progressBar->value()));
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
    ui->progressBar->setValue(ui->progressBar->value() + 1);

    if (ui->progressBar->value() < ui->progressBar->maximum())
    {
        qInfo() << "Downloading page" << ui->progressBar->value();
        d->download(ui->editUrl->text().arg(ui->progressBar->value()));
    }
    else
    {
        delete stream_;
        delete file_;
        stream_ = Q_NULLPTR;
        file_ = Q_NULLPTR;

        d->deleteLater();
        
        ui->progressBar->setValue(ui->progressBar->maximum());
        enableUI(true);
        QMessageBox::information(this, QString(), tr("Done."));
    }
}


void TyWidget::enableUI(bool enable)
{
    ui->editUrl->setEnabled(enable);
    ui->editFilename->setEnabled(enable);
    ui->editSelector->setEnabled(enable);
    ui->spinFrom->setEnabled(enable);
    ui->spinTo->setEnabled(enable);
    ui->buttonBrowse->setEnabled(enable);
    ui->buttonRun->setEnabled(enable);
}
