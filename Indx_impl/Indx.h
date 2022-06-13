#pragma once

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <mutex>
#include <list>
#include <regex>
#include "El.h"

/*
 * A1-9
 * B1-9
 *

*/

//std::mutex theMut;

class Indx {

public:
    Indx();

    void set(const std::string&);
    void plus(const int&);
    void minus(const int&);
    inline const std::list<El>& get() const { return this->__indx;};
    std::string toString() const;
    Indx& operator--(int);
    Indx& operator++(int);

    static constexpr short getMaxLen() { return _max_len;};
    static constexpr char getSeparator() { return _separator;};

private:
    std::list<El> __indx;
    // Working with built in ASCII character set has a size 128
    static constexpr short _max_len=10;
    static constexpr char _separator = '-';


public:
    static std::string const getMaxElem()
    {
        std::string res;
        for(auto i = 0; i < Indx::getMaxLen(); i++)
        {
            if ( i != 0 )
                res += Indx::getSeparator();
            res += El::_max_elem;
        }
        return res;
    };
};

