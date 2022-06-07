#include "gtest/gtest.h"
#include "../Indx_impl/El.h"

static auto test_letter_sec_size = static_cast<int>(El::_end_letter) - static_cast<int>(El::_start_letter) - sizeof(El::except_arr)/sizeof(decltype(*El::except_arr)) + 1;
static auto test_num_sec_size = static_cast<int>(El::_end_num) - static_cast<int>(El::_start_num) + 1;
static auto test_common_sec_size = test_letter_sec_size * test_num_sec_size;

TEST (DefaultConstructor, ConsisntecyCheck)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string(&El::_start_letter) + std::string(&El::_start_num));
}

TEST (Increment, simpleIncrement)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string("A1"));

    const char* example[] = {"A2" ,"A3" ,"A4" ,"A5" ,"A6" ,"A7" ,"A8" ,"A9" ,"B1" ,"B2" ,"B3" ,"B4" ,"B5" ,"B6" ,"B7" ,"B8" ,"B9" ,"C1" ,"C2" ,"C3" ,"C4" ,"C5" ,"C6" ,"C7" ,"C8" ,"C9" ,"E1" ,"E2" ,"E3" ,"E4" ,"E5" ,"E6" ,"E7" ,"E8" ,"E9" ,"H1" ,"H2" ,"H3" ,"H4" ,"H5" ,"H6" ,"H7" ,"H8" ,"H9" ,"I1" ,"I2" ,"I3" ,"I4" ,"I5" ,"I6" ,"I7" ,"I8" ,"I9" ,"K1" ,"K2" ,"K3" ,"K4" ,"K5" ,"K6" ,"K7" ,"K8" ,"K9" ,"L1" ,"L2" ,"L3" ,"L4" ,"L5" ,"L6" ,"L7" ,"L8" ,"L9" ,"N1" ,"N2" ,"N3" ,"N4" ,"N5" ,"N6" ,"N7" ,"N8" ,"N9" ,"O1" ,"O2" ,"O3" ,"O4" ,"O5" ,"O6" ,"O7" ,"O8" ,"O9" ,"P1" ,"P2" ,"P3" ,"P4" ,"P5" ,"P6" ,"P7" ,"P8" ,"P9" ,"R1" ,"R2" ,"R3" ,"R4" ,"R5" ,"R6" ,"R7" ,"R8" ,"R9" ,"S1" ,"S2" ,"S3" ,"S4" ,"S5" ,"S6" ,"S7" ,"S8" ,"S9" ,"T1" ,"T2" ,"T3" ,"T4" ,"T5" ,"T6" ,"T7" ,"T8" ,"T9" ,"U1" ,"U2" ,"U3" ,"U4" ,"U5" ,"U6" ,"U7" ,"U8" ,"U9" ,"W1" ,"W2" ,"W3" ,"W4" ,"W5" ,"W6" ,"W7" ,"W8" ,"W9" ,"X1" ,"X2" ,"X3" ,"X4" ,"X5" ,"X6" ,"X7" ,"X8" ,"X9" ,"Y1" ,"Y2" ,"Y3" ,"Y4" ,"Y5" ,"Y6" ,"Y7" ,"Y8" ,"Y9" ,"Z1" ,"Z2" ,"Z3" ,"Z4" ,"Z5" ,"Z6" ,"Z7" ,"Z8" ,"Z9" };
    for(auto i=0; i < test_common_sec_size - 1; i++ )
    {
        anImpl++;
        EXPECT_EQ(std::string(anImpl.get()), std::string(example[i]));
    }
}

TEST (Increment, overFlow)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string("A1"));
    anImpl.set(El::_max_elem);
    EXPECT_EQ(std::string(anImpl.get()), std::string(El::_max_elem));

    EXPECT_ANY_THROW(anImpl++);
}

TEST (Sum, simpleSum)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string("A1"));

    anImpl.plus(7);
    EXPECT_EQ(std::string(anImpl.get()), std::string("A8"));

    anImpl++;
    EXPECT_EQ(std::string(anImpl.get()), std::string("A9"));

    anImpl.plus(100);
    EXPECT_EQ(std::string(anImpl.get()), std::string("S2"));
}

TEST (Sum, overFlow)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string("A1"));

    EXPECT_ANY_THROW(anImpl.plus(test_common_sec_size+1));

}

TEST (Minus, simpleMinus)
{
    auto anImpl = El();
    EXPECT_EQ(std::string(anImpl.get()), std::string("A1"));

    anImpl.plus(100);
    std::cout << anImpl.get() << std::endl;
    //EXPECT_EQ(std::string(anImpl.get()), std::string("A8"));

    anImpl--;
    std::cout << anImpl.get() << std::endl;

    //EXPECT_EQ(std::string(anImpl.get()), std::string("A9"));

    anImpl.minus(50);
    std::cout << anImpl.get() << std::endl;

    //EXPECT_EQ(std::string(anImpl.get()), std::string("S2"));
}