/** Definition for singly-linked list.*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        ListNode *count = head;
        int len = 0;
        while (count != nullptr)
        {
            len++;
            count = count->next;
        }
        if (len == n)
            head = head->next;
        else
        {
            while (len > 0)
            {
                if (len - n == 1 && temp->next->next == nullptr)
                {
                    temp->next = nullptr;
                    break;
                }
                else if (len - n == 1 && temp->next != nullptr)
                {
                    temp->next = temp->next->next;
                    break;
                }
                cout << len - n << " " << temp->val << endl;
                len--;
                temp = temp->next;
            }
        }
        return head;
    }
};
int main()
{
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(0, new ListNode(3))));
    Solution S;
    l1 = S.removeNthFromEnd(l1, 5);
    while (l1 != nullptr)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    return 0;
}
