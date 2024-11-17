#include <gtest/gtest.h>
extern "C" {
    #include "example.h"  // Include your C headers here
}

// Test the `add` function
TEST(ExampleTest, AddFunction) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, -1), -2);
}

// Test the `subtract` function
TEST(ExampleTest, SubtractFunction) {
    EXPECT_EQ(subtract(5, 3), 2);
    EXPECT_EQ(subtract(0, 7), -7);
}
