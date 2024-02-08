#include "NetworkScanner.h"
#include <iostream>
#include <QAbstractListModel>

QList<Network> NetworkScanner::scanForNetworks()
{
    std::cout << "Called the C++ Network scanner class" << std::endl;

    QList<Network> networks;

    Network example1 = Network("Gita 2.4Ghz");
    networks.append(example1);

    return networks;
}

NetworksModel::NetworksModel(QObject *parent)
:
    QAbstractListModel(parent)
{
}

int NetworksModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->m_networks.count();
}

QVariant NetworksModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= this->m_networks.count())
    {
        return QVariant();
    }
    if (!index.isValid())
    {
        return QVariant();
    }

    const Network& network = this->m_networks.at(index.row());
    qDebug() << "role: " << role << " vs. " << NameRole;
    qDebug() << "network: " << network.name();
    if (role == NameRole)
    {
        return network.name();
    }

    return QVariant();
}

void NetworksModel::scan()
{
    beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount());

    QList<Network> networks = this->m_networkScanner.scanForNetworks();
    for (const Network& network: networks)
    {
        qDebug() << "Got network: " << network.name() << Qt::endl;
        this->m_networks << network;
    }

    qDebug() << "now have " << this->m_networks.size() << Qt::endl;

    endInsertRows();
}

QHash<int, QByteArray> NetworksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NetworksModel::NetworkRoles::NameRole] = "name";
    return roles;
}

Network::Network(const QString &name)
    : m_name(name)
{
}

QString Network::name() const
{
    return this->m_name;
}
