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
    void plus(const int&);
    El& operator++(int);
    void minus(const int&);
    El& operator--(int);


    static constexpr char _start_letter = 'A';
    static constexpr char _end_letter = 'Z';
    static constexpr char _start_num = '1';
    static constexpr char _end_num = '9';
    static constexpr char _max_elem[] = {_end_letter,_end_num};
    static constexpr char _min_elem[] = {_start_letter,_start_num};
    static constexpr char* except_arr[] = {"D", "F", "G", "J", "M", "Q", "V"};
    static constexpr short _max_num_len = static_cast<int>(_end_num) - static_cast<int>(_start_num) + 1;

private:
    bool isException(char&);

    short _num;
    char _liter;
};

