The main.cpp file is for example only and is not required.

scan() args:
const std::string &address // IPv4/6 host address.
std::vector <PortStatus> *psv // Port list as ptr on vector of PortStatus.
const uint64_t &timeout // ms delay beteen scans and max scan time.
const uint8_t &parallel // numbers of scans in same time.
bool IPv6 // true = IPv6, false = IPv4, def. false.
