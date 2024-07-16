#include <iostream>
#include <vector>
// #include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        ListNode *p1 = lists[0], *p2 = lists[1], *p3 = lists[2];
        ListNode *newlklist = mergetwoLists(p1, p2);
        ListNode *reslklist = mergetwoLists(newlklist, p3);
        return reslklist; 
    }

    ListNode* mergetwoLists(ListNode* head1, ListNode* head2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = head1, *p2 = head2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        }
        if (p2 != nullptr) {
            p->next = p2;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};





// 辅助函数：从整数向量创建链表
ListNode* createList(const std::vector<int>& values) {
    ListNode* dummy = new ListNode(-1);
    ListNode* current = dummy;
    for (size_t i = 0; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    // 创建多个链表并存储在一个vector中
    std::vector<ListNode*> lists;
    lists.push_back(createList({5, 7, 9}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution so;
    ListNode* res = so.mergeKLists(lists);
    for (ListNode* p = res; p != nullptr; p = p->next){
        std::cout << p->val << std::endl;
    }
    return 0;
}