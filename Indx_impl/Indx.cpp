#include "Indx.h"
Indx::Indx()
{
    __indx=std::list<El>();
}

void Indx::set(const char* aStr)
{

}

void Indx::plus_one()
{
    if(__indx.empty())
    {
        std::cout << __PRETTY_FUNCTION__ << ":: __indx.empty()" << std::endl;
        __indx.emplace_back(El());
    } else
    {
        if (__indx.back().get() == El::_max_elem)
        {
            if (__indx.size() >= Indx::max_len)
            {
                throw std::out_of_range("Max size [" + std::to_string(Indx::max_len) + "] has been reached");
            } else {
                __indx.emplace_back(El());
            }
        } else
        {
            __indx.back()++;
        }
    }
}




