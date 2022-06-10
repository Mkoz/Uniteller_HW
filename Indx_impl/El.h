#pragma once//

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <list>


class El {

public:
    El();
    void set(const char*);
    std::string get() const;
    void plus(const int&);
    El& operator++(int);
    void minus(const int&);
    El& operator--(int);

    static constexpr char _start_liter = 'A';
    static constexpr char _end_liter = 'Z';
    static constexpr char _start_num = '1';
    static constexpr char _end_num = '9';
    static constexpr char _max_elem[] = {_end_liter, _end_num};
    static constexpr char _min_elem[] = {_start_liter, _start_num};
    static constexpr char* _except_arr[] = {"D", "F", "G", "J", "M", "Q", "V"};
    static constexpr short _max_num_len = static_cast<int>(_end_num) - static_cast<int>(_start_num) + 1;
    static constexpr short _max_liter_len = static_cast<int>(_end_liter) - static_cast<int>(_start_liter) + 1 \
                                            - sizeof(_except_arr)/sizeof(*_except_arr);

private:
    bool isException(char&);

    short _num;
    char _liter;
};

