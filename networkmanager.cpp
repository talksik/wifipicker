#include "networkmanager.h"
#include <iostream>
#include <QAbstractListModel>
#include <iwlib.h>
#include <string>
#include <vector>
#include <sstream>
#include <network.h>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

QList<Network> NetworkManager::scanForNetworks()
{
    std::cout << "Called the C++ Network scanner class" << std::endl;

    QList<Network> networks;

    Network example1 = Network("Gita 2.4Ghz");
    networks.append(example1);

    std::string result = exec("nmcli -t -f ssid dev wifi");

    std::vector<std::string> ssids;
    std::istringstream iss(result);
    std::string line;
    while (std::getline(iss, line)) {
        if (!line.empty() && line != "O.o")
        {
            ssids.push_back(line);
        }
    }

    for (const std::string &ssid : ssids) {
        Network newNetwork = Network(ssid.c_str());
        networks.append(newNetwork);
    }

    return networks;
}

bool NetworkManager::isWifiEnabled()
{
    std::string result = exec("nmcli radio wifi");
    if (result.find("enabled") != std::string::npos)
    {
        return true;
    }

    return false;
}

bool NetworkManager::connect(std::string ssid, std::string password)
{
    try {
        std::string command = "nmcli device wifi connect \"" + ssid + "\" password \"" + password + "\"";
        std::string result = exec(command.c_str());
        return true;
    } catch(...) {
        return false;
    }
}
