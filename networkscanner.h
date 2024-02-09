#ifndef NETWORKSCANNER_H
#define NETWORKSCANNER_H

#include <QObject>
#include <QAbstractListModel>

class Network
{
public:
    Network(const QString &name);

    QString name() const;
private:
    QString m_name;
};

class NetworkScanner : public QObject
{
    Q_OBJECT
public:
    QList<Network> scanForNetworks();
};

#endif // NETWORKSCANNER_H
