#pragma once//

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <mutex>
#include <list>


class El {

public:
    El();
    void set(const char*);
    const char* get();
    void plus_one();
    static constexpr char __start_letter = 'A';
    static constexpr char __end_letter = 'Z';
    static constexpr char __start_num = '1';
    static constexpr char __end_num = '9';
    static inline const char* __max_elem = strstr(&__end_letter, &__end_num);


private:
    bool isException(char&);
    static constexpr char* except_arr[] = {"D", "F", "G", "J", "M", "Q", "V"};


    short _num;
    char _liter;
};

