/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		ListNode *Result = new ListNode(1);
		ListNode *Temp = Result;
		if (list1 == nullptr)
			return list2;
		else if (list2 == nullptr)
			return list1;
		while (list1!= nullptr && list2!= nullptr)
		{
			if (list1->val >= list2->val)
			{
				Temp->next = new ListNode(list2->val);
				list2 = list2->next;
			}
			else
			{
				Temp->next = new ListNode(list1->val);
				list1 = list1->next;
			}
			Temp = Temp->next;
		}
		if (list1 == nullptr && list2 == nullptr)
			return Result->next;
		else if (list1 == nullptr)
		{
			Temp->next = list2;
			return Result->next;
		}
		Temp->next = list1;
		return Result->next;
		
	}
};
