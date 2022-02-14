/**
 * Definition for singly-linked list.*/
#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode* output=nullptr;
        for (ListNode* e:lists){
            output=merge2Lists(output,e);
        }
        return output;
    }
    ListNode *merge2Lists(ListNode *l1, ListNode *l2)
    {
        ListNode *point = new ListNode(0);
        ListNode *head = point;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                point->next=l1;
                l1=l2;
                l2=point->next->next;
            }
            else{
                point->next=l2;
                l2=l1;
                l1=point->next->next;
            }
            point=point->next;
        }
        if (l1!=nullptr){
            point->next=l1;
        }
        else if (l2!= nullptr){
            point->next=l2;
        }
        return head->next;
    }
};
int main()
{
    ListNode *l1 = new ListNode(3, new ListNode(5, new ListNode(6)));
    ListNode *l2 = new ListNode(4, new ListNode(7, new ListNode(10)));
    ListNode *l3 = new ListNode(1, new ListNode(5, new ListNode(13)));
    Solution S;
    vector<ListNode*> v={l1,l2,l3};
    ListNode* Sol2 = S.mergeKLists(v);
    while (Sol2){
        cout<<Sol2->val<<" ";
        Sol2=Sol2->next;
    }
    return 0;
}