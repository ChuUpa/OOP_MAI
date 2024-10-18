#include <gtest/gtest.h>
#include "../include/Ternary.hpp"
#include "../include/Vector.hpp"

TEST(TernaryTests, DefaultConstructor) {
    Ternary ternary;
    Vector res = ternary.getNumber();

    Vector expected(0);

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SizeAndValueConstructor) {
    Ternary ternary(3, 2);
    Vector res = ternary.getNumber();

    Vector expected = {2, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, InitializerListConstructor) {
    Ternary ternary({1, 2, 2});
    Vector res = ternary.getNumber();

    Vector expected = {2, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, StringConstructor) {
    Ternary ternary("122");
    Vector res = ternary.getNumber();

    Vector expected = {2, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, GreaterThanOperator) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({0, 2, 1});

    EXPECT_TRUE(ternary1 > ternary2);
    EXPECT_FALSE(ternary2 > ternary1);
}

TEST(TernaryTests, LessThanOperator) {
    Ternary ternary1({0, 2, 1});
    Ternary ternary2({1, 2, 2});

    EXPECT_TRUE(ternary1 < ternary2);
    EXPECT_FALSE(ternary2 < ternary1);
}

TEST(TernaryTests, EqualToOperator) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({1, 2, 2});
    Ternary ternary3({0, 2, 1});

    EXPECT_TRUE(ternary1 == ternary2);
    EXPECT_FALSE(ternary1 == ternary3);
}

TEST(TernaryTests, AdditionOperator_1) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({2, 1, 0});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {2, 0, 1, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionOperator_2) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({2, 1});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionOperator_3) {
    Ternary ternary1({2, 2, 2});
    Ternary ternary2({1, 1, 1});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 1, 1, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionOperator_4) {
    Ternary ternary1({2, 2, 2});
    Ternary ternary2({1, 1});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 1, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionOperator_5) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({0});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {2, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionOperator_6) {
    Ternary ternary1({0});
    Ternary ternary2({0});

    Ternary result = ternary1 + ternary2;
    Vector res = result.getNumber();

    Vector expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_1) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({0, 2, 1});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {1, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_2) {
    Ternary ternary1({2, 1, 0});
    Ternary ternary2({1, 0});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 0, 2};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_3) {
    Ternary ternary1({2, 0, 0});
    Ternary ternary2({1, 1, 0});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 2};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_4) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({0, 2, 1});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {1, 0, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_5) {
    Ternary ternary1({2, 2, 2});
    Ternary ternary2({1, 1, 1});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {1, 1, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_6) {
    Ternary ternary1({2, 2, 2});
    Ternary ternary2({0, 0, 2});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {0, 2, 2};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_7) {
    Ternary ternary1({1, 0, 0});
    Ternary ternary2({0, 1, 1});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {2, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_8) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({0, 0, 0});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {2, 2, 1};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_9) {
    Ternary ternary1({0, 0, 0});
    Ternary ternary2({0, 0, 0});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, SubtractionOperator_10) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({1, 2, 2});

    Ternary result = ternary1 - ternary2;
    Vector res = result.getNumber();

    Vector expected = {0};

    EXPECT_EQ(res, expected);
}

TEST(TernaryTests, AdditionAssignmentOperator) {
    Ternary ternary1({1, 2, 2});
    Ternary ternary2({2, 1});

    ternary1 += ternary2;
    Vector res = ternary1.getNumber();

    Vector expected = {0, 0, 0, 1};
}

