
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        if (p1 == nullptr) return p2;
        if (p2 == nullptr) return p1;
        while (p1 != nullptr && p2 != nullptr){
            if (p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            }
            else if (p1->val >= p2->val){
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (!p1){
            p->next = p2;                
        }
        if (!p2){
            p->next = p1;
        }
        return dummy->next;
    }
};

int main(){
    Solution so;
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    ListNode* list2 = new ListNode(3);
    list1->next = new ListNode(4);
    ListNode* res = so.mergeTwoLists(list1, list2);
    return 0;
}