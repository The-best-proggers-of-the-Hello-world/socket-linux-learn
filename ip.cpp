#include "ip.h"

IP::IP()
{
    set(LOCALHOST);
}

IP::IP(string str)
{
    set(str);
}

IP::~IP() {}

void IP::set(string str)
{
    str_ip = str;
    adr_ip = inet_addr(str_ip.c_str());
    vector<string> tmp_v;
    boost::split(tmp_v, str_ip, boost::is_any_of("."));

    if (tmp_v.size() != 4)
    {
        perror("IP set index");
        exit(-1);
    }

    ip[0] = atoi(tmp_v[0].c_str());
    ip[1] = atoi(tmp_v[1].c_str());
    ip[2] = atoi(tmp_v[2].c_str());
    ip[3] = atoi(tmp_v[3].c_str());

    if (ip[0] < 0 || ip[0] > 255 || ip[1] < 0 || ip[1] > 255 || ip[2] < 0 || ip[2] > 255 || ip[3] < 0 || ip[3] > 255)
    {
        perror("IP set index");
        exit(-1);
    }
}

void IP::set(int i, unsigned short val)
{
    if (i < 0 || i > 3 || val < 0 || val > 255)
    {
        perror("IP set index");
        exit(-1);
    }
    ip[i] = val;
    str_ip = to_string(ip[0]) + "." + to_string(ip[1]) + "." + to_string(ip[2]) + "." + to_string(ip[3]);
    adr_ip = inet_addr(str_ip.c_str());
}

void IP::set(unsigned short p0, unsigned short p1, unsigned short p2, unsigned short p3)
{

    if (p0 < 0 || p0 > 255 || p1 < 0 || p1 > 255 || p2 < 0 || p2 > 255 || p3 < 0 || p3 > 255)
    {
        perror("IP set index");
        exit(-1);
    }

    ip[0] = p0;
    ip[1] = p1;
    ip[2] = p2;
    ip[3] = p3;
    str_ip = to_string(ip[0]) + "." + to_string(ip[1]) + "." + to_string(ip[2]) + "." + to_string(ip[3]);
    adr_ip = inet_addr(str_ip.c_str());
}

string IP::getIPstr()
{
    return str_ip;
}

in_addr_t IP::getIPhex()
{
    return adr_ip;
}