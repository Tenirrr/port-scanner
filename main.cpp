// FOR EXAMPLE PURPOSE ONLY!

#include "port-scanner.hpp"

using namespace std;

int main() {
    vector <PortStatus> ports;
    PortStatus port;

    port.port = 22;
    ports.push_back(port);
    port.port = 43;
    ports.push_back(port);
    port.port = 57;
    ports.push_back(port);
    port.port = 80;
    ports.push_back(port);
    port.port = 443;
    ports.push_back(port);
    port.port = 3306;
    ports.push_back(port);
    port.port = 26666;
    ports.push_back(port);
    PortScanner::TCP tcp = PortScanner::TCP();

    tcp.scan("127.0.0.1", &ports, 500, 2, false);
    for (auto &v: ports) {
        printf("PORT: %i STATUS: %i\n", v.port, v.status);
    }

    return 0;
}