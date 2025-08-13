// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=196&tqId=37081&ru=/exam/oj
/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param lists ListNode类vector
     * @return ListNode类
     */
    ListNode* mergeList(ListNode* l1, ListNode* l2) 
    {
        ListNode dummy(0); 
        ListNode* tail = &dummy;

        while (l1 && l2) 
        {
            if (l1->val < l2->val) 
            {
                tail->next = l1;
                l1 = l1->next;
            } 
            else 
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* _mergeKLists(vector<ListNode*>& lists, int left, int right) 
    {
        if (left == right) return lists[left];  
        if (left > right) return nullptr;      

        int mid = left + (right - left) / 2;
        ListNode* l1 = _mergeKLists(lists, left, mid); 
        ListNode* l2 = _mergeKLists(lists, mid + 1, right); 
        return mergeList(l1, l2); 
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return _mergeKLists(lists, 0, lists.size() - 1);
    }
};