#include <iostream>
#include "Indx_impl/Indx.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto el = El();
/*
    std::cout << el.get() << std::endl;
    for(auto i = 0; i < 170; i++)
    {
        el++;
        std::cout << el.get() << std::endl;
    }
    el.set("A2");
*/

    auto ind = Indx();
    std::cout << ind.get().size() << std::endl;

    ind.plus_one();
    std::cout << ind.get().size() << std::endl;


    for(auto str : ind.get())
    {
        std::cout << str.get();
    }
    return 0;
}
