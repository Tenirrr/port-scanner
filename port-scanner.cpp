#include "port-scanner.hpp"

using namespace PortScanner;
using namespace std;

int8_t try2connect(const string &address, PortStatus *ps, const bool &IPv6 = 0) {
     struct sockaddr_in target {
        .sin_family = AF_INET,
        .sin_port = htons(ps->port)
    };   
    
    if (IPv6) target.sin_family = AF_INET6;

    inet_pton(target.sin_family, address.c_str(), &target.sin_addr);

    int s = socket(target.sin_family, SOCK_STREAM, 0);
    int c = connect(s, (struct sockaddr *) & target, sizeof(target));

    ps->status = c ? 1:0;
    shutdown(s, SHUT_RDWR);
    return 0;
}

int8_t TCP::scan(const std::string &address, std::vector <PortStatus> *psv, const uint64_t &timeout, const uint8_t &parallel, bool IPv6) {
    if (parallel <= 0) return -1;
    
    vector <thread> threads;
    uint16_t s = 0, f = 0;

    while (f < psv->size()) {
        for (uint16_t i = 0; i < parallel && s < psv->size(); i++) {
            PortStatus *ps = &psv->at(s);
            ps->status = 2;
            threads.push_back(thread(&try2connect, address, ps, IPv6));
            s++;
        }

        usleep(timeout * 1'000);

        for (uint16_t i = 0; i < parallel && f < psv->size(); i++) {
            threads.at(i).detach();
            threads.at(i).~thread();
            f++;
        }
        threads.clear();
    }
    return 0;
}