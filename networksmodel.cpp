#include "networksmodel.h"

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
    if (role == NameRole)
    {
        return network.name();
    }

    return QVariant();
}

void NetworksModel::scan()
{
    beginResetModel();

    QList<Network> networks = this->m_networkmanager.scanForNetworks();
    this->m_networks = networks;

    endResetModel();
}

QHash<int, QByteArray> NetworksModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NetworksModel::NetworkRoles::NameRole] = "name";
    return roles;
}

void NetworksModel::connectToNetwork(const QString &ssid, const QString &password)
{
    bool success = this->m_networkmanager.connect(ssid.toStdString(), password.toStdString());
}
