#include <sstream>
#include "Indx.h"
Indx::Indx()
{
    __indx=std::list<El>();
    //Construct first element El::_start_liter + El::_start_num
    __indx.emplace_back(El());
}

void Indx::plus(const int& aPlus)
{
    if(__indx.empty())
    {
        __indx.emplace_back(El());
    } else
    {
        for( auto i = aPlus; i > 0; --i)
        {
            // Add new entries
            if (__indx.back().get() == El::_max_elem)
            {
                if (__indx.size() >= Indx::_max_len)
                {
                    throw std::out_of_range("Max size [" + std::to_string(Indx::_max_len) + "] has been reached");
                } else {
                    __indx.emplace_back(El());
                }
            } else {
                __indx.back()++;
            }
        }
     }
}

std::string Indx::toString() const
{
    std::string res;
    for( auto it = __indx.begin(); it != __indx.end(); it++)
    {
        if(it != __indx.begin())
            res+='-';
        res+=std::string((*it).get());
    }
    return res;
}

void Indx::minus(const int& aValue)
{

    for( auto i = aValue; i > 0; --i) {
        if (__indx.back().get() == El::_min_elem) {
            if (__indx.size() == 1) {
                throw std::out_of_range("Min size [" + std::string(El::_min_elem) + "] has been reached");
            } else {
                __indx.pop_back();
            }
        } else {
            __indx.back()--;
        }
    }

}

void Indx::set(const std::string& s)
{

    // TODO make checks more strict
    std::string aStr = Indx::getSeparator() \
            + std::string("?([") \
            + El::_start_liter \
            + '-' \
            + El::_end_liter \
            + ']' + '[' \
            + El::_start_num \
            + '-' \
            + El::_end_num \
            + ']' + ')'
            +Indx::getSeparator() \
            + '?';

    std::regex re(aStr);

    std::smatch match;
    short i = 1;
    if(regex_search(s, match, re))
    {
        if (match.position() != 0)
            throw std::runtime_error("Bad set string " + s);
        __indx.clear();
        auto str = match.suffix().str();
        auto tmpEl = El(); // TODO create appropriate constructor to El
        tmpEl.set(match[1].str().c_str());
        __indx.emplace_back(tmpEl);
        while(regex_search(str, match ,re))
        {
            if (match.position() != 0)
                throw std::runtime_error("Bad set string " + s);
            str = match.suffix().str();
            tmpEl.set(match[1].str().c_str());
            __indx.emplace_back(tmpEl);
        }
        if (match.suffix().str().size() != 0)
        {
            throw std::runtime_error("Bad set string " + s);
        }
    }
    else
    {
        throw std::runtime_error("Bad set string " + s);
    }
}

Indx& Indx::operator-- (int)
{
    this->minus(1);
    return *this;
}

Indx& Indx::operator++ (int)
{
    this->plus(1);
    return *this;
}







