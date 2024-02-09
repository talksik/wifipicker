#include "network.h"

Network::Network(const QString &name)
    : m_name(name)
{
}

QString Network::name() const
{
    return this->m_name;
}
