
#include <cstddef>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // traverse linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution so;
    so.hasCycle()
}