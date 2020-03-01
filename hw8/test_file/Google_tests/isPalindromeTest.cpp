//
// Created by Lawrence Hon on 2/29/20.
//

#include "gtest/gtest.h"
#include "hw8_q2.cpp"

// positive tests
TEST(isPalindromeTestSuite, PositiveTest) {
EXPECT_EQ(isPalindrome("level"), true);
}