#ifndef __BANK_H
#define __BANK_H

#include "client.h"
#include "account.h"

class Bank {
private:
    Client** m_clients;
    int m_clients_count;
    int m_clients_index;
    Account** m_accounts;
    int m_accounts_count;
    int m_accounts_index;

public:
    Bank(int t_c, int t_a);
    Client*  get_client(int t_c);
    Account* get_account(int t_a);
    Client*  create_client(int t_c, const char* t_n);
    Account* create_account(int t_n, Client* t_c);
    Account* create_account(int t_n, Client* t_c, double t_ir);
    Account* create_account(int t_n, Client* t_c, Client* t_p);
    Account* create_account(int t_n, Client* t_c, Client* t_p, double t_ir);
    void     add_interest();
    void     print();
    bool     m_check_if_exits(int t_n);
    bool     deposit_for(Account* t_a, double t_d);
    bool     withdraw_for(Account* t_a, double t_d);
};

#endif//__BANK_H
