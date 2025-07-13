// https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=196&tqId=37147&ru=%2Fexam%2Foj&dayCountBigMember=365%E5%A4%A9
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // 反转链表
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        ListNode dummy(0); // 使用哑节点避免内存管理问题
        ListNode* tail = &dummy;
        
        // 逐位相加
        while(head1 || head2 || carry) {
            if(head1) {
                carry += head1->val;
                head1 = head1->next;
            }
            if(head2) {
                carry += head2->val;
                head2 = head2->next;
            }
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }
        
        // 反转结果链表
        return reverse(dummy.next);
    }
    
    // 修复后的反转链表函数
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr) {
            ListNode* nextNode = curr->next; // 保存下一个节点
            curr->next = prev; // 当前节点指向前驱
            prev = curr; // 前驱后移
            curr = nextNode; // 当前节点后移
        }
        
        return prev; // 返回新的头节点
    }
};

int main() 
{
    Solution sol;
    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);
    
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    ListNode* result = sol.addInList(head1, head2);
    
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}