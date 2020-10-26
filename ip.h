#ifndef IP_H
#define IP_H

#ifdef __linux__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#elif _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#endif

#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

#define LOCALHOST "127.0.0.1"

class IP
{
protected:
    string str_ip;
    in_addr_t adr_ip;
    unsigned short ip[4];

public:
    IP();
    IP(string);
    virtual ~IP();

    void set(int, unsigned short);
    void set(string);
    void set(unsigned short, unsigned short, unsigned short, unsigned short);

    string getIPstr();
    in_addr_t getIPhex();
};

#endif