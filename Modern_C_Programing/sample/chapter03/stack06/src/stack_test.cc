#include "gtest/gtest.h"

#include <stdbool.h>
#include "stack.h"

TEST(StackTest, popFromEmptyStackReturnsFalse) {
    int buf[16];
    Stack stack = newStack(buf);
    EXPECT_EQ(false, pop(&stack, 0));
}

TEST(StackTest, popReturnsStackTopAndRemoveIt) {
    int buf[16];
    Stack stack = newStack(buf);

    EXPECT_EQ(true, push(&stack, 123));

    int ret;
    EXPECT_EQ(true, pop(&stack, &ret));
    EXPECT_EQ(123, ret);

    EXPECT_EQ(false, pop(&stack, &ret));
}

TEST(StackTest, pushToFullStackReturnsFalse) {
    int buf[16];
    Stack stack = newStack(buf);

    for (int i = 0; i < 16; ++i) push(&stack, i);
    EXPECT_EQ(false, push(&stack, 100));

    int ret;
    EXPECT_EQ(true, pop(&stack, &ret));
    EXPECT_EQ(15, ret);
}

TEST(StackTest, pushWithRangeCheck) {
    int buf[16];
    Range range = {0, 9};
    Validator validator = rangeValidator(&range);
    Stack stack = newStackWithValidator(buf, &validator);
    EXPECT_EQ(false, push(&stack, -1));
    EXPECT_EQ(false, push(&stack, 10));
}

TEST(StackTest, pushWithPreviousCheck) {
    int buf[16];
    PreviousValue previous = {0};
    Validator validator = previousValidator(&previous);
    Stack stack = newStackWithValidator(buf, &validator);
    EXPECT_EQ(true, push(&stack, 3));
    EXPECT_EQ(false, push(&stack, 2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
