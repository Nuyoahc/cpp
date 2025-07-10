#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int l1 = 0, l2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        while(p1)
        {
            p1 = p1->next;
            l1++;
        }
        while(p2)
        {
            p2 = p2->next;
            l2++;
        }
        if(l1 > l2)
        {
            for(int i = 0; i < l1 - l2; i++)
            {
                headA = headA->next;
            }
        }
        else
        {
            for(int i = 0; i < l2 - l1; i++)
            {
                headB = headB->next;
            }
        }
        while(headA && headB)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main()
{
    Solution solution;

    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    ListNode *headB = new ListNode(4);
    headB->next = headA->next;  // Intersect at node with value 2

    ListNode *intersection = solution.getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found." << endl;
    
    return 0;
}