#include "include/account.h"

#define ERROR "<<ERROR>> "
#define FUNC  "@fn: '" << __PRETTY_FUNCTION__ << "' "

Account::Account(int t_n, Client* t_c)
    : m_number(t_n), m_owner(t_c)
{}

Account::Account(int t_n, Client* t_c, double t_ir)
    : m_number(t_n)
    , m_interest_rate(t_ir)
    , m_owner(t_c)
{}

Account::Account(int t_n, Client* t_c, Client* t_p)
    : m_number(t_n)
    , m_owner(t_c)
    , m_partner(t_p)
{}

Account::Account(int t_n, Client* t_c, Client* t_p, double t_ir)
    : m_number(t_n)
    , m_interest_rate(t_ir)
    , m_owner(t_c)
    , m_partner(t_p)
{}

int Account::get_number() {
    return this->m_number;
}

double Account::get_balance() {
    return this->m_balance;    
}

double Account::get_ir() {
    return this->m_interest_rate;
}

void Account::set_ir(double t_ir) {
    m_interest_rate = t_ir;
}

Client* Account::get_owner() {
    return this->m_owner;
}

Client* Account::get_partner() {
    return m_partner;
}

bool Account::can_withdraw(double t_a) {
    double bal = m_balance;    
    if(bal - t_a >= 0) {
        return true;
    } else return false;
}

void Account::deposit(double t_a) {
    m_balance += t_a;
}

bool Account::withdraw(double t_a) {
    if(can_withdraw(t_a)) {
        m_balance -= t_a;
        return true;
    } else {
        std::cout << ERROR << FUNC
            << "Insifficient funds for withdraw!"
            << std::endl;
        return false;
    }
}

void Account::add_interest() {
    m_balance += m_balance * m_interest_rate;
}

