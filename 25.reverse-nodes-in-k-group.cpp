/**
 * Definition for singly-linked list.*/
#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=nullptr;
        int count=0;
        if (head==nullptr) return nullptr;
        if (lengthLL(head)<k) return curr;
        while (curr!=nullptr && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
            count++;
        }
        if (next!=nullptr) head->next=reverseKGroup(next,k);
        return prev;

    }
    int lengthLL(ListNode* head){
        ListNode* Temp=head;
        int count=0;
        while(Temp!=nullptr){
            count++;
            Temp=Temp->next;
        }
        return count;
    }
};
int main(){
    Solution S;
    ListNode* l1=new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* d=S.reverseKGroup(l1,2);
    while (d!=nullptr){
        cout<<d->val<<" ";
        d=d->next;
    }
}
