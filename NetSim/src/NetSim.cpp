#include <iostream>
#include <memory>
#include "Physical Layer.h"
#include <string>

int main()
{
    L1::Connection* con = new L1::Connection{ 10 };

    L1::Machine* m1 = new L1::Machine("Lolkek");
    L1::Machine* m2 = new L1::Machine();

    Connect(m1, con);
    Connect(m2, con);
    
    m1->tick_func = [](L1::Machine& self)
    {
        std::cout << self << "Works!\n";
    };

    for (int i = 0; i < 10; i++)
        m1->Tick();

    return 0;
}
