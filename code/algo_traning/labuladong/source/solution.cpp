// File: source/solution.cpp
#include "../include/solution.h"

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode *dummy1 = new ListNode(-1), *dy1 = dummy1;
    ListNode *dummy2 = new ListNode(-1), *dy2 = dummy2;
    ListNode *p1 = head;
    while (p1 != nullptr){
        if (p1->val < x){
            dy1->next = p1;
            dy1 = dy1->next;
        }
        else{
            dy2->next = p1;
            dy2 = dy2->next;
        }
        p1 = p1->next;
    }
    dy2->next = nullptr;  // 防止循环引用
    dy1->next = dummy2->next;
    ListNode* result = dummy1->next;
    delete dummy1;
    delete dummy2;
    return result;
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return nullptr;
        }
        ListNode *p1 = lists[0], *p2 = lists[1], *p3= lists[2];
        ListNode *newlklist = mergetwoLists(p1, p2);
        ListNode *reslklist = mergetwoLists(newlklist, p3);
        return reslklist; 
    }
    ListNode* mergetwoLists(ListNode* head1, ListNode* head2){
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = head1, *p2 = head2;
        while (p1 != nullptr && p2 != nullptr){
            if (p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
            if (p1 != nullptr){
                p->next = p1;
            }
            if (p2 != nullptr){
                p->next = p2;
            }
        }
        return dummy->next;
    }