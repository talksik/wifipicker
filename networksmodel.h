#ifndef NETWORKSMODEL_H
#define NETWORKSMODEL_H

#include <QAbstractListModel>
#include "networkscanner.h"

class NetworksModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum NetworkRoles
    {
        NameRole = Qt::UserRole + 1
    };

    NetworksModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void scan();

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Network> m_networks;
    NetworkScanner m_networkScanner;
};

#endif // NETWORKSMODEL_H
