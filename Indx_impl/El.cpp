#include "El.h"
El::El()
{
    _num=1;
    _liter='A';
}

void El::plus(const int& aVal)
{
    if( strcmp(this->get().c_str(), El::_max_elem) == 0 )
    {
        throw std::out_of_range("Max size [" + std::string(El::_max_elem) + "] has been reached");
    }
    auto tmp = _num + aVal;
    auto counter = tmp/El::_max_num_len;
    if(tmp > El::_max_num_len)
    {
        _num = tmp%El::_max_num_len;
        if (_num == 0)
        {
            ++_num;
        }
        while(counter) {
            do {
                _liter += 1;
                if(static_cast<int>(_liter) > static_cast<int>(El::_end_liter))
                    throw std::out_of_range("Max size [" + std::string(El::_max_elem) + "] has been reached");
            } while (isException(_liter));
            --counter;
        }
    } else
    {
        _num=tmp;
    }
}

El& El::operator++ (int)
{
    this->plus(1);
    return *this;
}

void El::minus(const int& aVal)
{
    if( strcmp(this->get().c_str(), El::_min_elem) == 0 )
    {
        throw std::out_of_range("Min size [" + std::string(El::_min_elem) + "] has been reached");
    }
    auto tmp = _num - aVal;
    auto counter = tmp == 0 ? 1 : aVal/El::_max_num_len;

    if(tmp < static_cast<int>(El::_start_num) - static_cast<int>('0'))
    {
        _num = std::abs(tmp%El::_max_num_len);
        if (_num == 0)
        {
            _num+=El::_max_num_len;
        }
        while(counter) {
            do {
                _liter -= 1;
                if(static_cast<int>(_liter) < static_cast<int>(El::_start_liter))
                {
                    throw std::out_of_range("Min size [" + std::string(El::_min_elem) + "] has been reached");
                }
            } while (isException(_liter));
            --counter;
        }
    } else
    {
        _num=tmp;
    }
}

El& El::operator-- (int)
{
    this->minus(1);
    return *this;
}


bool El::isException(char& aVal)
{
    for(auto i: El::_except_arr)
    {
        if(*i == aVal)
        {
            return true;
        }
    }
    return false;
}

std::string El::get() const
{
    return std::string(_liter + std::to_string(_num));
}

void El::set(const char* aStr)
{
    if( std::strlen(aStr) != 2 )
    {
        throw std::length_error( "Incorrect initialize str size");
    }
    _num=int(aStr[1]) - int('0');
    _liter=aStr[0];
}