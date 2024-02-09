#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include <network.h>
#include <string>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    QList<Network> scanForNetworks();
    bool isWifiEnabled();
    bool connect(std::string ssid, std::string password);
};

#endif // NETWORKMANAGER_H
