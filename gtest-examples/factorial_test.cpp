#include "factorial.h"
#include <gtest/gtest.h>

class factorialTest : public testing::Test {
    protected:
    factorial f;
};
TEST_F (factorialTest,negative) {
    EXPECT_EQ (1,f.calculate_factorial(-5));
}
TEST_F (factorialTest,positive) {
    EXPECT_EQ (24,f.calculate_factorial(4));
}
TEST_F (factorialTest,positive2) {
    ASSERT_EQ(0,f.calculate_factorial(-1));
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc,argv);
    return(RUN_ALL_TESTS());
}
