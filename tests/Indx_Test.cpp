#include "gtest/gtest.h"
#include "../Indx_impl/Indx.h"

static auto test_letter_sec_size = static_cast<int>(El::_end_liter) - static_cast<int>(El::_start_liter) - sizeof(El::_except_arr) / sizeof(decltype(*El::_except_arr)) + 1;
static auto test_num_sec_size = static_cast<int>(El::_end_num) - static_cast<int>(El::_start_num) + 1;
static auto test_common_sec_size = test_letter_sec_size * test_num_sec_size;

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

    anImpl.set(Indx::getMaxElem());
    EXPECT_EQ(anImpl.toString(), std::string(Indx::getMaxElem()));

    anImpl.minus(3);
    EXPECT_EQ(anImpl.toString(), std::string("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z6"));

    anImpl.minus(test_common_sec_size);
    EXPECT_EQ(anImpl.toString(), std::string("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z6"));

    anImpl.minus(test_common_sec_size/2);
    EXPECT_EQ(anImpl.toString(), std::string("Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-O2"));

    anImpl.minus(4 * test_common_sec_size);
    EXPECT_EQ(anImpl.toString(), std::string("Z9-Z9-Z9-Z9-O2"));
}

TEST (Indx_Sub, decrement)
{
    auto anImpl = Indx();
    constructCheck(anImpl);

    anImpl.set(Indx::getMaxElem());
    EXPECT_EQ(anImpl.toString(), std::string(Indx::getMaxElem()));

    for(auto i = Indx::getMaxLen()*test_common_sec_size - 1; i > 0; --i)
    {
        anImpl--;
    }
    EXPECT_EQ(anImpl.toString(), std::string(El::_min_elem));
    std::cout << __PRETTY_FUNCTION__ << " : " << anImpl.toString() << std::endl;
}

TEST (Indx_Sub, minSizeException)
{
    auto anImpl = Indx();
    constructCheck(anImpl);
    EXPECT_ANY_THROW(anImpl--);
}

TEST (Indx_Set, simpleSet)
{

    auto anImpl = Indx();
    constructCheck(anImpl);

    const char* example_arr[] = { "Z9-Z9-Z9-A1", "Z1-B2", "T5", "Z9-B3"};

    for (auto ex : example_arr)
    {
        anImpl.set(ex);
        EXPECT_EQ(anImpl.toString(), std::string(ex));
    }
}

TEST (Indx_Set, badSetExcaption)
{

    auto anImpl = Indx();
    constructCheck(anImpl);

    const char* example_arr[] = { "bla-bla@@@@-Z3-blablaZ9-Z9-Z9-A1", "-asd-Tasd5", "asdasdasd"};

    for (auto ex : example_arr)
    {
        std::cout << ex <<std::endl;
        EXPECT_ANY_THROW(anImpl.set(ex));
    }
}

TEST (Indx_Set, differentTypes)
{
    auto anImpl = Indx();
    constructCheck(anImpl);
    const char* testValue = "T1";
    using ex = std::variant<decltype(std::string(testValue)),\
                decltype(testValue)>;

    std::vector<ex> anArr = {std::string(testValue), testValue};

    for ( auto& i : anArr)
    {
        std::visit([&](auto arg){
                anImpl.set(arg);
                EXPECT_EQ(anImpl.toString(), std::string(arg));
        }, i);
    }
}


TEST (Indx_GetMaxElem, getMaxElem)
{
    std::string example;
    for(auto i = 0; i < Indx::getMaxLen(); i++)
    {
        if ( i != 0)
        {
            example += Indx::getSeparator();
        }
        example += El::_max_elem;
    }
    EXPECT_EQ(Indx::getMaxElem(), example);
}