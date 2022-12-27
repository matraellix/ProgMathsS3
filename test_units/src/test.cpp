#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

#include "Ratio.hpp"

//constructors
TEST (RatioConstructor, defaultConstructor) { 
	Ratio r;
	EXPECT_EQ (r, 0);
}

TEST (RatioConstructor, copyConstructor) {
	Ratio r1(1,2);
	//copy constructor
	Ratio r2(r1);
	ASSERT_EQ(r1, r2);
}

// arithmetic
TEST (RatioArithmetic, plus) {
	Ratio r1(1,2);
	Ratio r2(5,6);
	Ratio r3 = r1+r2;
	ASSERT_EQ(r3, r1 + r2);
}

TEST (RatioArithmetic, minus) {
	Ratio r1(1,2);
	Ratio r2(5,6);
	Ratio r3 = r1 - r2;
	ASSERT_EQ(r3, r1 - r2);
}

TEST (RatioArithmetic, dot) {
	Ratio r1(1,2);
	Ratio r2(5,6);
	Ratio r3 = r1 * r2;
	ASSERT_EQ(r3.get_num(), r1.get_num() * r2.get_num());
	ASSERT_EQ(r3.get_denom(), r1.get_denom() * r2.get_denom());
	ASSERT_EQ(r3, r1 * r2);
}

TEST (RatioArithmetic, divide) {
	Ratio r1(1,2);
	Ratio r2(5,6);
	Ratio r3 = r1 / r2;
	int gcd = std::gcd(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_EQ(r3.get_num(), (r1.get_num()*r2.get_denom())/gcd);
	ASSERT_EQ(r3.get_denom(), (r1.get_denom() * r2.get_num())/gcd);
	ASSERT_EQ(r3, r1 / r2);
}

TEST (RatioArithmetic, modulo) {
	Ratio r1(3,4);
	Ratio r2(5,2);
	Ratio r3 = r1 % r2;
	int gcd = std::gcd(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	int num = (r1.get_num() * r2.get_denom()) % ( r1.get_denom() * r2.get_num());
	ASSERT_EQ(r3.get_num(), num/gcd);
	ASSERT_EQ(r3.get_denom(), (r1.get_denom() * r2.get_denom())/gcd);
	ASSERT_EQ(r3, r1 % r2);
}

// comparison
TEST (RatioComparison, equal) {
	Ratio r1(1,2);
	Ratio r2(2,4);
	ASSERT_EQ(r1, r2);
	ASSERT_EQ(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_EQ(r1, 0.5);
	ASSERT_EQ(0.5, r2);

}

TEST (RatioComparison, strict_superior) {
	Ratio r1(3,2);
	Ratio r2(1,2);
	ASSERT_GT(r1, r2);
	ASSERT_GT(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_GT(r1, 0.75);
	ASSERT_GT(1, r2);

}

TEST (RatioComparison, superior_equal) {
	Ratio r1(3,2);
	Ratio r2(1,2);
	ASSERT_GE(r1, r2);
	ASSERT_GE(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_GE(r1, 0.75);
	ASSERT_GE(0.5, r2);

}

TEST (RatioComparison, strict_inferior) {
	Ratio r1(1,2);
	Ratio r2(3,2);
	ASSERT_LT(r1, r2);
	ASSERT_LT(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_LT(r1, 0.75);
	ASSERT_LT(1, r2);

}

TEST (RatioComparison, inferior_equal) {
	Ratio r1(1,2);
	Ratio r2(3,2);
	ASSERT_LE(r1, r2);
	ASSERT_LE(r1.get_num()*r2.get_denom(), r1.get_denom()*r2.get_num());
	ASSERT_LE(r1, 0.75);
	ASSERT_LE(0.5, r2);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}