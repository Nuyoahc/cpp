#include <iostream>
#include <vector>

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
    bool isPalindrome(ListNode* head)
    {
        vector<int> a;
        while(head)
        {
            a.push_back(head->val);
            head = head->next;
        }
        // 判断回文
        for(int i = 0; i < a.size() / 2; i++)
        {
            if(a[i] != a[a.size() - 1 - i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    bool result = solution.isPalindrome(head);
    cout << (result ? "true" : "false") << endl;

    return 0;
}