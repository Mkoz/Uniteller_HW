#include "El.h"
El::El()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    _num=1;
    _liter='A';
}

void El::plus_one()
{
    std::cout << "plus_one:: ";
    if(_num == 9)
    {
        std::cout << "if(_num == 9)";
        _num=1;
        do{
            _liter+=1;
        } while(isException(_liter));
    } else
    {
        std::cout << "else";
        ++_num;
    }
    std::cout<<std::endl;
}

bool El::isException(char& aVal)
{
    for(auto i: El::except_arr)
    {
        if(*i == aVal)
        {
            return true;
        }
    }
    return false;
}

const char* El::get()
{
    return std::string(_liter + std::to_string(_num)).c_str();
}

void El::set(const char* aStr)
{
    if( std::strlen(aStr) != 2 )
    {
        throw std::length_error( "Too big inialize str" );
    }
    _num=int(aStr[1]) - int('0');
    _liter=aStr[0];
}