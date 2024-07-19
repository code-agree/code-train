#include <gtest/gtest.h>
#include <cmath>
#include "PostfixCalculator.h"  // 假设这是你的计算器类的头文件

class PostfixCalculatorTest : public ::testing::Test {
protected:
    PostfixCalculator calc;
};

TEST_F(PostfixCalculatorTest, BasicOperations) {
    EXPECT_NEAR(calc.evaluate("3 4 +"), 7.0, 1e-6);
    EXPECT_NEAR(calc.evaluate("5 2 -"), 3.0, 1e-6);
    EXPECT_NEAR(calc.evaluate("3 4 *"), 12.0, 1e-6);
    EXPECT_NEAR(calc.evaluate("6 2 /"), 3.0, 1e-6);
}

TEST_F(PostfixCalculatorTest, ComplexExpressions) {
    EXPECT_NEAR(calc.evaluate("3 4 2 * +"), 11.0, 1e-6);
    EXPECT_NEAR(calc.evaluate("5 1 2 + 4 * + 3 -"), 14.0, 1e-6);
}

TEST_F(PostfixCalculatorTest, PowerAndSquareRoot) {
    EXPECT_NEAR(calc.evaluate("2 3 pow"), 8, 1e-6);
    EXPECT_NEAR(calc.evaluate("16 sqrt"), 4, 1e-6);
}

TEST_F(PostfixCalculatorTest, DecimalsAndNegatives) {
    EXPECT_NEAR(calc.evaluate("3.5 2.1 +"), 5.6, 1e-6);
    EXPECT_NEAR(calc.evaluate("-5 3 +"), -2.0, 1e-6);
}

TEST_F(PostfixCalculatorTest, BoundaryValues) {
    // EXPECT_TRUE(std::isinf(calc.evaluate("1e308 10 *")));
    // EXPECT_LT(calc.evaluate("1e-308 10 /"), 1e-307);
}

TEST_F(PostfixCalculatorTest, ExceptionHandling) {
    // EXPECT_THROW(calc.evaluate("3 +"), std::runtime_error);
    // EXPECT_THROW(calc.evaluate("3 4 5 +"), std::runtime_error);
    // EXPECT_THROW(calc.evaluate("3 0 /"), std::runtime_error);
}

TEST_F(PostfixCalculatorTest, EmptyExpression) {
    EXPECT_THROW(calc.evaluate(""), std::runtime_error);
}

TEST_F(PostfixCalculatorTest, InvalidToken) {
    EXPECT_THROW(calc.evaluate("3 4 & +"), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}