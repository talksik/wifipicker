#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include <network.h>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    QList<Network> scanForNetworks();
};

#endif // NETWORKMANAGER_H
