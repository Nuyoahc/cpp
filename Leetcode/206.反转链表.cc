class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* curNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = curNext;
        }     
        return prev;   
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            // 存储cur的下一位
            ListNode* curNext = cur->next;
            // 头插
            cur->next = newHead;
            newHead = cur;
            cur = curNext;
        }
        return newHead;
    }
};