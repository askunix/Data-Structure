//合并两个有序链表



ListNode* MergeTwoOrderList(ListNode* L1, ListNode* L2)
{
	
	if(L1 == NULL && L2 == NULL)
	{
		return LL;
	}
	if(L1 == NULL)
	{
		retrun L2;
	}
	if(L2 == NULL)
	{
		return L1;
	}
	
	ListNode* cur = new ListNode(0);
	ListNode* newList = cur;
	
	while(L1 != NULL && L2 != NULL)
	{
		if(L1->val > L2->val)
		{
			cur->next = L2;
			L2 = L2->next;
		}
		
		else
		{
			cur->next = L1;
			L1 = L1->next;
		}
		
		cur = cur->next;
	}
	
	if(L1 == NULL)
	{
		cur->next = L2;
	}
	else
	{
		cur->next = L1;
	}
	
	return newList->next;
}
