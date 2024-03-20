#include <iostream>
#include "include/bank.h"

#define ARRLEN(x) sizeof(x)/sizeof(*x)

const int cli_id_base = 123456;
const int acc_id_base = 789456;

struct Person {
    const char* m_name;
    const int   m_id;
};

Person people_list[] = {
    { "Jan",    cli_id_base * 1 }, 
    { "Jakub",  cli_id_base * 2 }, 
    { "Adam",   cli_id_base * 3 }, 
    { "Josef",  cli_id_base * 4 }, 
    { "Michal", cli_id_base * 5 }, 
    { "Daniel", cli_id_base * 6 },
    { "Adela",  cli_id_base * 7 },
    { "Eliska", cli_id_base * 8 },
    { "Patrik", cli_id_base * 9 },
    { "Julie",  cli_id_base * 10 },
    { "Matej",  cli_id_base * 11 },
};

int main() {
    const int N = ARRLEN(people_list);
    Bank b1{1000, 1000};

    // vytvoření klientů v bance
    for(Person p : people_list) {
        b1.create_client(p.m_id, p.m_name);
    }

    // vytvoření účtů některých klientů
    for(int i = 1; i <= N/2 ; ++i) {
        b1.create_account(acc_id_base*i, b1.get_client(cli_id_base*i));
    }

    // vytvoření účtů s partnerem 
    for(int i = N/2; i < 2 * N/2; ++i) {
        b1.create_account(acc_id_base*i, b1.get_client(cli_id_base*i), b1.get_client(cli_id_base*(i+1)));
    }

    // vkládání peněz do účtů
    for(int i = 1; i <= 2 * N/2; ++i) {
        b1.deposit_for(b1.get_account(acc_id_base*i), 5000.05*i);
    }

    // výběr peněz z účtů
    for(int i = 1; i <= 3; ++i) {
        b1.withdraw_for(b1.get_account(acc_id_base*i), 4000.05*i);
    }

    // adice úroků do účtů
    b1.add_interest();
    
    // výpis banky - účty a klienti
    b1.print();
    
    return 0;
}
