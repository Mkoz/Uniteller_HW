#include "Indx.h"
Indx::Indx()
{
    __indx=std::list<El>();
    __indx.emplace_back(El());
}

void Indx::plus(const int& aPlus)
{
    if(__indx.empty())
    {
        __indx.emplace_back(El());
    } else
    {
        std::cout << __PRETTY_FUNCTION__ << " :El::_max_elem: " << El::_max_elem << std::endl;
        std::cout << __PRETTY_FUNCTION__ << " :__indx.back().get(): " << __indx.back().get() << std::endl;
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

void Indx::set(const char* aStr)
{
    auto s = std::string(aStr);

    std::string::size_type prev_pos = 0, pos = 0;
    auto tmpEl = El();
    __indx.clear();
    while((pos = s.find('-', pos)) != std::string::npos)
    {
        std::string substring( s.substr(prev_pos, pos - prev_pos) );


        tmpEl.set(substring.c_str());
        __indx.push_back(tmpEl);

        prev_pos = ++pos;
    }
    tmpEl.set(s.substr(prev_pos, pos-prev_pos).c_str()); // Last word
    __indx.push_back(tmpEl);

}





