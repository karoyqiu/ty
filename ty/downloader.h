/*! ***********************************************************************************************
 *
 * \file        downloader.h
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
#pragma once
#include <QObject>
#include <Selector.hpp>

class QNetworkAccessManager;


class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader(QNetworkAccessManager *manager, QObject *parent = Q_NULLPTR);
    virtual ~Downloader();

    void setSelector(gq::SharedSelector value);

    QString text() const
    {
        return text_;
    }

public slots:
    void download(const QUrl &url);

signals:
    void finished();

private slots:
    void handleReply();

private:
    QNetworkAccessManager *manager_;
    gq::SharedSelector selector_;
    QString text_;
};
