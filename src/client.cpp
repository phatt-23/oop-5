#include "include/client.h"

Client::Client(int t_code, const char* t_name)
: m_code(t_code), m_name(t_name) {}

int Client::get_code() {
    return this->m_code;
}

const std::string& Client::get_name() {
    return this->m_name;
}

