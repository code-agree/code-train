// File: testcase/test_partition.cpp
#include "../include/solution.h"
#include <iostream>
#include <vector>
#include <cassert>

// Helper function to create a linked list from a vector
ListNode* createList(const std::vector<int>& values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    for (size_t i = 0; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to convert a linked list to a vector
std::vector<int> listToVector(ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Helper function to delete a linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test function
void testPartition() {
    Solution solution;

    // Test case 1
    int arr1[] = {1, 4, 3, 2, 5, 2};
    std::vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    int x1 = 3;
    ListNode* head1 = createList(input1);
    ListNode* result1 = solution.partition(head1, x1);
    std::vector<int> output1 = listToVector(result1);
    int expectedArr1[] = {1, 2, 2, 4, 3, 5};
    std::vector<int> expected1(expectedArr1, expectedArr1 + sizeof(expectedArr1) / sizeof(expectedArr1[0]));
    assert(output1 == expected1);
    deleteList(result1);
    std::cout << "Test case 1 passed!" << std::endl;

    // Test case 2 (edge case: empty list)
    ListNode* head2 = nullptr;
    ListNode* result2 = solution.partition(head2, 0);
    assert(result2 == nullptr);
    std::cout << "Test case 2 passed!" << std::endl;

    // Test case 3 (edge case: all elements smaller than x)
    int arr3[] = {1, 2, 3};
    std::vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(arr3[0]));
    int x3 = 4;
    ListNode* head3 = createList(input3);
    ListNode* result3 = solution.partition(head3, x3);
    std::vector<int> output3 = listToVector(result3);
    assert(output3 == input3);
    deleteList(result3);
    std::cout << "Test case 3 passed!" << std::endl;

    // Test case 4 (edge case: all elements greater than or equal to x)
    int arr4[] = {4, 5, 6};
    std::vector<int> input4(arr4, arr4 + sizeof(arr4) / sizeof(arr4[0]));
    int x4 = 4;
    ListNode* head4 = createList(input4);
    ListNode* result4 = solution.partition(head4, x4);
    std::vector<int> output4 = listToVector(result4);
    assert(output4 == input4);
    deleteList(result4);
    std::cout << "Test case 4 passed!" << std::endl;

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    testPartition();
    return 0;
}