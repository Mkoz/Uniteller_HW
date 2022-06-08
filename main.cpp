#include <iostream>
#include "Indx_impl/Indx.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto el = El();

    std::cout << ((int)El::_end_num-(int)El::_start_num) << std::endl;

    for(auto i = 0; i < ((int)El::_end_num-(int)El::_start_num + 1)* \
                        ((int)El::_end_letter - (int)El::_start_letter - \
                        sizeof(El::_except_arr)/sizeof(*El::_except_arr) + 1) -1; i++)
    {
        el.plus(1);
        std::cout << el.get() << " ";
    }
    std::cout << std::endl;
    el.set("A2");


    auto ind = Indx();
    std::cout << ind.get().size() << std::endl;

    ind.plus(1);
    std::cout << ind.get().size() << std::endl;


    for(auto str : ind.get())
    {
        std::cout << str.get();
    }
    return 0;
}
