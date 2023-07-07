//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代反转单链表
ListNode* reverser(ListNode* head){
	ListNode* prev, *curr, *next;
	prev = nullptr;
	curr = head;
	next = head;
	while (curr != nullptr){
        next = curr->next;
		curr->next = prev;
		prev = curr;	
		curr = next;
    }
	// 返回反转后的头节点，因为循环的终止条件是curr == null；那么prev指针就是头节点指针。
	return prev;
};


// 递归反转单链表
//明确递归函数的定义；输入头节点指针，反转后返回新的头节点
ListNode* reverser(ListNode* head){
	if (head == nullptr || head->next == nullptr){
		return head;
	}
	ListNode* last = reverser(head->next);
	head->next->next = head;
	head->next = nullptr;
	return last;
};