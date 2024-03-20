#include "include/bank.h"

Bank::Bank(int t_c, int t_a)
    : m_clients_count(t_c), m_clients_index(0)
    , m_accounts_count(t_a), m_accounts_index(0)
{
    this->m_clients = new Client*[t_c];
    this->m_accounts = new Account*[t_a];
}

Client* Bank::get_client(int t_c) {
    for(int i = 0; i < m_clients_count; ++i) {
        if(m_clients[i]->get_code() == t_c) return m_clients[i];
    }
    return nullptr;
}

Account* Bank::get_account(int t_a) {
    for(int i = 0; i < m_accounts_count; ++i) {
        if(m_accounts[i]->get_number() == t_a) return m_accounts[i];
    }
    return nullptr;
}

Client* Bank::create_client(int t_c, const char* t_n) {
    Client* c = new Client{t_c, t_n};
    m_clients[m_clients_index] = c;
    m_clients_index++;
    return c;
}

Account* Bank::create_account(int t_n, Client* t_c) {
    Account* a = new Account{t_n, t_c};
    m_accounts[m_accounts_index] = a;
    m_accounts_index++;
    return a;
}

Account* Bank::create_account(int t_n, Client* t_c, double t_ir) {
    Account* a = new Account{t_n, t_c, t_ir};
    m_accounts[m_accounts_index] = a;
    m_accounts_index++;
    return a;
}

Account* Bank::create_account(int t_n, Client* t_c, Client* t_p) {
    Account* a = new Account{t_n, t_c, t_p};
    m_accounts[m_accounts_index] = a;
    m_accounts_index++;
    return a;
}

Account* Bank::create_account(int t_n, Client* t_c, Client* t_p, double t_ir) {
    Account* a = new Account{t_n, t_c, t_p, t_ir};
    m_accounts[m_accounts_index] = new Account{t_n, t_c, t_p, t_ir};
    m_accounts_index++;
    return a;
}

void Bank::add_interest() {
    for(int i = 0; i < m_accounts_count; ++i) {
        m_accounts[i]->add_interest();
    } 
}

void Bank::print() {
    std::cout << "Accounts:" << std::endl;
    for(int i = 0; i < m_accounts_index; ++i) {
        std::cout 
            << m_accounts[i]->get_number() << ", "
            << m_accounts[i]->get_balance() << ", "
            << m_accounts[i]->get_ir() << ", "
            << std::endl;
    }
    std::cout << "Clients:" << std::endl;
    for(int i = 0; i < m_clients_index; ++i) {
        std::cout 
            << m_clients[i]->get_code() << ", "
            << m_clients[i]->get_name() << ", "
            << std::endl;
    }
}