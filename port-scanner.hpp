#ifndef PORT_SCANNER_HPP
#define PORT_SCANNER_HPP

#include <string>
#include <inttypes.h>
#include <thread>
#include <unistd.h>
#include <vector>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

typedef struct {
    uint16_t port;
    int8_t status = -1;
} PortStatus;

namespace PortScanner {
    class TCP
    {
    private:
    public:
        int8_t scan(const std::string &, std::vector <PortStatus> *, const uint64_t &, const uint8_t &, bool = 0);
    };
}

#endif