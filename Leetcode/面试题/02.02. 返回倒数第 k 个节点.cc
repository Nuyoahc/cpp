#include <iostream>
#include <string>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode *cur = head;
        int l = 0;
        while(cur)
        {
            l++, cur = cur->next;
        }
        for(int i = 0; i < (l - k); i++)
        {
            head = head->next;
        }
        return head->val;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution sol;
    cout << sol.kthToLast(head, 2) << endl;
    return 0;
}