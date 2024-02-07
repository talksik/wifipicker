#ifndef NETWORKSCANNER_H
#define NETWORKSCANNER_H

#endif // NETWORKSCANNER_H

#include <QObject>

// class Network
// {
// public:
//     enum NetworkStatus {
//         Connected = 0,
//         Available
//     };

//     Network(const QString &name, const NetworkStatus &status);

//     QString name;
//     NetworkStatus status;
// };

class NetworkScanner : public QObject
{
    Q_OBJECT
public slots:
    void scan();
};
