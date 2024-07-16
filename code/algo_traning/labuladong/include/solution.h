// File: include/solution.h
#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x);
    ListNode* mergeKLists(vector<ListNode*>& lists)
};

#endif // SOLUTION_H