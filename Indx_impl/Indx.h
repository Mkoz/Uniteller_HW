#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include <mutex>
#include <list>
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

    //operator+(Indx&,const int&);
    void plus(const int&);
    void minus(const int&);
    void set(const char*);
    inline const std::list<El>& get() const { return this->__indx;};
    std::string toString() const;

    static constexpr short getMaxLen() { return _max_len;};

private:
    std::list<El> __indx;
    static constexpr short _max_len=10;

    //static constexpr char str_arr5[][max_len]
    /*
    static constexpr std::vector<std::string> storage= [](){
        for(short i = 0; i < Indx.max_len ; i++ )
        {
            Indx.storage.push();
        }
    };*/
/*private:


    static constexpr short num_of_letter = int(__end_letter) - int(__start_letter) - sizeof(Indx::except_arr)/sizeof(decltype(&except_arr));
    static constexpr short num_of_number = int(__end_num) - int(__start_num);
    static constexpr char* list_of_entries[fact()] = [](std::initializer_list<const char*>)
            {
                return std::initializer_list<const char*>();
            };
*/

};

