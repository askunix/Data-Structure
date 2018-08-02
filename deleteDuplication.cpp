#include<iostream>

struct LinkList
{
	int data;
	struct LinkList *next;
	LinkList(int x) :
		data(x), next(NULL)
	{}
};

class Solution{
public:
	LinkList *uniqueTwo(LinkList *L)
	{
		LinkList *re, *pre, *cur;
		re = pre = L;
		cur = L->next;
		while (cur->next)
		{
			if (cur->data == cur->next->data)
			{
				pre = cur;//pre标记第一个重复节点
				while (cur->data == pre->data)//依次删除后续重复节点
				{
					pre->next = cur->next;
					cur = pre->next;
				}
				re->next = cur;//删除第一个重复节点
				pre = re;
			}
			else
			{
				re = re->next;
				pre = re;
				cur = pre->next;
			}
		}
	}
};


//class Solution
//{
//public:
//	ListNode *deleteDuplication(ListNode* pHead)
//	{
//		if (pHead == NULL || pHead->next == NULL)
//		{
//			return pHead;
//		}
//
//		ListNode *p1 = (ListNode*)malloc(sizeof(int));
//		p1->next = NULL;    //p1记录没有重复的节点
//		ListNode* head = p1;
//		ListNode* p2 = pHead;  //p2用于遍历原来的链表
//
//		while (p2)
//		{
//			if (p2->next && p2->val == p2->next->val)
//			{
//				while (p2->next && p2->val == p2->next->val)
//				{
//					p2 = p2->next;
//				}
//
//				p2 = p2->next;
//
//				p1->next = p2;
//			}
//
//			else   //没有重复节点
//			{
//				p1->next = p2; 
//				p1 = p2;
//				p2 = p2->next;
//			}
//		}
//		return head->next;
//	}
//
//};


