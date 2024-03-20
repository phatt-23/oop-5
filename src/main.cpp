#include <iostream>
#include "include/bank.h"

const char* name_list[] = {
    "Kokot",
    "Kurva",
    "Debil"
};
int main() {

    const int N = 3;
    Bank b1{N, N};

#if 1
    for(int i = 0; i < N; ++i) {
        b1.create_client(123*i, name_list[i]);
        b1.create_account(12*i, b1.get_client(123*i));
    }
#endif

    b1.print();
    
    return 0;
}
