#include "gtest/gtest.h"
#include "../Indx_impl/Indx.h"

void constructCheck(const Indx& indx)
{
    EXPECT_EQ(indx.toString(), std::string(&El::_start_liter) + std::string(&El::_start_num));
    EXPECT_EQ(indx.get().size(),1 );
}

TEST (Indx_DefaultConstructor, ConsisntecyCheck)
{
    auto anImpl = Indx();
    constructCheck(anImpl);
}

TEST (Indx_Sum, simpleSum)
{
    auto anImpl = Indx();
    constructCheck(anImpl);
    anImpl.plus(1);
    EXPECT_EQ(anImpl.toString(), "A2");

    anImpl.plus(5);
    EXPECT_EQ(anImpl.toString(), "A7");

    anImpl.plus(10);
    EXPECT_EQ(anImpl.toString(), "B8");

    anImpl.plus(100);
    EXPECT_EQ(anImpl.toString(), "S9");


    anImpl.plus(El::_max_liter_len * El::_max_num_len);
    EXPECT_EQ(anImpl.toString(), "Z9-S9");

    anImpl.plus(3 * El::_max_liter_len * El::_max_num_len);
    EXPECT_EQ(anImpl.toString(), "Z9-Z9-Z9-Z9-S9");

}

TEST (Indx_Sum, overflow) {
    auto anImpl = Indx();
    constructCheck(anImpl);

    EXPECT_ANY_THROW(anImpl.plus( El::_max_liter_len * El::_max_num_len * Indx::getMaxLen()));

}
TEST (Indx_Sub, simpleSub)
{
    auto anImpl = Indx();
    constructCheck(anImpl);

}

TEST (Indx_Set, simpleSet)
{

    auto anImpl = Indx();
    constructCheck(anImpl);

    anImpl.set("Z9-Z9-Z9-A1");

    std::cout << __PRETTY_FUNCTION__ << " : " << anImpl.toString() << std::endl;

    anImpl.set("S1");

    std::cout << __PRETTY_FUNCTION__ << " : " << anImpl.toString() << std::endl;

}
