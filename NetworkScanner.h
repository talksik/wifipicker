#ifndef NETWORKSCANNER_H
#define NETWORKSCANNER_H

#endif // NETWORKSCANNER_H

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

private:
    QList<Network> m_networks;
    NetworkScanner m_networkScanner;
};
