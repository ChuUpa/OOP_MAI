#include <gtest/gtest.h>
#include <function.h>

TEST(Test, Number_1) {
    int a = 94;

    std::string result = translator(a);

    EXPECT_EQ(result, "doksan dört");
}

TEST(Test, Number_2) {
    int a = 1;

    std::string result = translator(a);

    EXPECT_EQ(result, "bir");
}

TEST(Test, Number_3) {
    int a = 13;

    std::string result = translator(a);

    EXPECT_EQ(result, "on üç");
}

TEST(Test, Number_4) {
    int a = 27;

    std::string result = translator(a);

    EXPECT_EQ(result, "yirmi yedi");
}

TEST(Test, Number_5) {
    int a = 38;

    std::string result = translator(a);

    EXPECT_EQ(result, "otuz sekiz");
}

TEST(Test, Number_6) {
    int a = 77;

    std::string result = translator(a);

    EXPECT_EQ(result, "yetmiş yedi");
}

TEST(Test, Number_7) {
    int a = 0;

    std::string result = translator(a);

    EXPECT_EQ(result, "sıfır");
}

TEST(Test, Number_8) {
    int a = 99;

    std::string result = translator(a);

    EXPECT_EQ(result, "doksan dokuz");
}

TEST(Test, Number_9) {
    int a = 9;

    std::string result = translator(a);

    EXPECT_EQ(result, "dokuz");
}

TEST(Test, Number_10) {
    int a = 52;

    std::string result = translator(a);

    EXPECT_EQ(result, "elli iki");
}