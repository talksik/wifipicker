#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>

class Network
{
public:
    Network(const QString &name);

    QString name() const;
private:
    QString m_name;
};

#endif // NETWORK_H
