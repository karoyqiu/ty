/*! ***********************************************************************************************
 *
 * \file        downloader.cpp
 * \brief       Downloader 类。
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
#include "downloader.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <Document.hpp>


Downloader::Downloader(QNetworkAccessManager *manager, QObject *parent)
    : QObject(parent)
    , manager_(manager)
{
    Q_ASSERT(manager != Q_NULLPTR);
}


Downloader::~Downloader()
{
}


void Downloader::setSelector(gq::SharedSelector value)
{
    selector_ = value;
}


void Downloader::download(const QUrl &url)
{
    text_.clear();
    auto *reply = manager_->get(QNetworkRequest(url));
    connect(this, &QObject::destroyed, reply, &QObject::deleteLater);
    connect(reply, &QNetworkReply::finished, this, &Downloader::handleReply);
}


void Downloader::handleReply()
{
    auto *reply = qobject_cast<QNetworkReply *>(sender());
    Q_ASSERT(reply);
    reply->deleteLater();

    try
    {
        auto all = reply->readAll();
        auto *codec = QTextCodec::codecForHtml(all);
        auto html = codec->toUnicode(all).toStdString();

        auto doc = gq::Document::Create();
        doc->Parse(html);

        auto nodes = doc->Find(selector_);

        for (size_t i = 0; i < nodes.GetNodeCount(); i++)
        {
            auto *node = nodes.GetNodeAt(i);

            QString s = QString::fromStdString(node->GetText()).trimmed();

            if (!s.isEmpty())
            {
                text_.append(s);
                text_.append(QS("\n"));
            }
        }
    }
    catch (const std::runtime_error &e)
    {
        qCritical() << "EXCEPTION:" << e.what();
    }

    emit finished();
}
