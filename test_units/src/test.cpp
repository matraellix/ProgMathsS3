#include <gtest/gtest.h>

#include "Ratio.hpp"

/*
TEST (RatioConstructor, defaultConstructor) { 
	Ratio r;
	EXPECT_EQ (0, r);
}
*/

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}