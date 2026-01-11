#include <gtest/gtest.h>
#include "List/ArrayList.hpp"

// Test fixture for ArrayList
class ArrayListTest : public ::testing::Test {
protected:
    ArrayList<int> list;

    void SetUp() override {
        // Optional: code to run before each test
    }
};

// Test initial state
TEST_F(ArrayListTest, IsEmptyInitially) {
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

// Test adding elements
TEST_F(ArrayListTest, AddElements) {
    list.add(10);
    list.add(20);
    list.add(1, 15); // Add at index

    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.get(0), 10);
    EXPECT_EQ(list.get(1), 15);
    EXPECT_EQ(list.get(2), 20);
}

// Test removing by index
TEST_F(ArrayListTest, RemoveByIndex) {
    list.add(10);
    list.add(20);
    int removed = list.remove(0);

    EXPECT_EQ(removed, 10);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 20);
}

// Test removing by element
TEST_F(ArrayListTest, RemoveByElement) {
    list.add(100);
    list.add(200);
    
    EXPECT_TRUE(list.removeElement(100));
    EXPECT_FALSE(list.removeElement(999)); // Element doesn't exist
    EXPECT_EQ(list.size(), 1);
}

// Test bounds checking (Exception testing)
TEST_F(ArrayListTest, ThrowsOutOfBounds) {
    list.add(10);
    EXPECT_THROW(list.get(5), std::out_of_range);
    EXPECT_THROW(list.remove(-1), std::out_of_range);
}

// Test string conversion
TEST_F(ArrayListTest, ToStringFormat) {
    list.add(1);
    list.add(2);
    // Assuming format like "[1, 2]" - adjust based on your implementation
    EXPECT_FALSE(list.toString().empty());
}