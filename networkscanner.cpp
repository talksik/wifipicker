#include "networkscanner.h"
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
