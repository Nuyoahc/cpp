#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int l1, l2;
        ListNode *cur1 = pHead1, *cur2 = pHead2;
        while (cur1)
        {
            cur1 = cur1->next;
            l1++;
        }
        while (cur2)
        {
            cur2 = cur2->next;
            l2++;
        }
        if (l1 > l2)
        {
            for (int i = 0; i < (l1 - l2); i++)
            {
                pHead1 = pHead1->next;
            }
        }
        else
        {
            for (int i = 0; i < (l2 - l1); i++)
            {
                pHead2 = pHead2->next;
            }
        }
        while (pHead1)
        {
            if (pHead1 == pHead2)
            {
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};

int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(2);
    ListNode *common = new ListNode(3);
    head1->next = common;
    head2->next = common;
    common->next = new ListNode(4);
    Solution solution;
    ListNode *result = solution.FindFirstCommonNode(head1, head2);
    if (result)
    {
        cout << "First common node value: " << result->val << endl;
    }
    else
    {
        cout << "No common node found." << endl;
    }    
    return 0;
}