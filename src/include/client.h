#ifndef __CLIENT_H
#define __CLIENT_H

#include "precompiled.h"

class Client {
private:
    int m_code;
    std::string m_name;
public:
    Client(int t_code, const char* t_name);
    ~Client() = default;

    int get_code();
    const std::string& get_name();
};

#endif//__CLIENT_H
