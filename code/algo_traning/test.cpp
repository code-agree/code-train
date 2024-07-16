#include <iostream>

using namespace std;
int main()
{
    int arr[10];
    for (int i = 0; i < 4; i++){
        arr[i] = i;
    }
    // for (int i = 4; i > 2; i--){
    //     arr[i] = arr[i - 1];
    // }
    // cout << arr[2] << endl;
    // arr[2] = 666;
    // cout << "xiugai" << endl;
    // cout << arr[2] << endl;
    for (int i = 0; i < 10; ++i){
        cout << arr[i] << endl;
    }
    
}




class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes to build two sublists: 
        // one for nodes with values < x, another for nodes with values >= x
        ListNode *dummy1 = new ListNode(-1), *dy1 = dummy1;  // dy1 builds the sublist for nodes < x
        ListNode *dummy2 = new ListNode(-1), *dy2 = dummy2;  // dy2 builds the sublist for nodes >= x
        ListNode *p = head;  // p is used to traverse the original list

        // Traverse the original list, distributing nodes to the appropriate sublist
        while (p != nullptr) {
            if (p->val < x) {
                dy1->next = p;  // Connect current node to the sublist of nodes < x
                dy1 = dy1->next;  // Move dy1 pointer to the end of its sublist
            } else {
                dy2->next = p;  // Connect current node to the sublist of nodes >= x
                dy2 = dy2->next;  // Move dy2 pointer to the end of its sublist
            }
            p = p->next;  // Move p pointer to the next node in the original list
        }

        // Handle the end of the lists
        dy2->next = nullptr;  // Ensure the end of the >= x sublist points to nullptr, preventing potential cycles

        // Connect the two sublists
        dy1->next = dummy2->next;  // Link the < x sublist to the >= x sublist

        // Return the head of the new list (skipping the dummy1 node)
        return dummy1->next;
    }
};