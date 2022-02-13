
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>
using namespace std;
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
    {
        ListNode *temp = l1;
        ListNode *end = l1;
        while (temp != nullptr && l2 != nullptr)
        {
            int x = temp->val + l2->val + carry;
            carry = x / 10;
            temp->val = x % 10;
            if (temp->next == nullptr)
                end = temp;
            temp = temp->next;
            l2 = l2->next;
        }
        if (l2 == nullptr && temp == nullptr && carry!=0) {
            end->next=new ListNode(carry);
        }
        while (l2 != nullptr)
        {
            int x = l2->val + carry;
            carry = x / 10;
            end->next = new ListNode(x % 10);
            end = end->next;
            if (l2->next == nullptr && carry != 0){
                end->next=new ListNode(carry);
                break;}
            
            l2= l2->next;
        }
        while (temp != nullptr)
        {
            int x = temp->val + carry;
            carry = x / 10;
            temp->val = x % 10;
            if (temp->next == nullptr && carry != 0){
                temp->next=new ListNode(carry);
                break;}
            temp = temp->next;
            
            
        }
        return l1;
    }
};

int main()
{
    Solution S;
    // ListNode *l1 = new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9))));
    // ListNode *l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9,new ListNode(9)))))));
    ListNode * l1 = new ListNode(5);
    ListNode * l2 = new ListNode(5);
    ListNode * l3 = S.addTwoNumbers(l1, l2);
    while (l3 != nullptr)
    {
        cout << l3->val << " ";
        l3 = l3->next;
    }
}
