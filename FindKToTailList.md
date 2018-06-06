
返回链表倒数第K个节点


```

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



#define DataType int

typedef struct Node
{
	DataType data;
	struct Node* _pNext;
}*pNode;




pNode InitNode(pNode pHead)
{
	pHead = NULL;
	return pHead;
}


pNode BuyNewNode(DataType data)
{
	pNode pNewNode = NULL;
	pNewNode = (pNode)malloc(sizeof(pNode));
	if (pNewNode)
	{
		pNewNode->data = data;
		pNewNode->_pNext = NULL;
	}
	return pNewNode;
}


void InstallFrontNode(pNode *pHead, DataType data)
{
	assert(pHead);
	pNode temp = NULL;

	if (*pHead == NULL)
		*pHead = BuyNewNode(data);

	else
	{
		temp = BuyNewNode(data);
		temp->_pNext = *pHead;
		*pHead = temp;
	}

}



void PrintList(pNode pHead)
{
	assert(pHead);
	
	while (pHead)
	{
		printf("%d -> ", pHead->data);
		pHead = pHead->_pNext;
	}
	printf("NULL");
	printf("\n");
}



pNode FindKToTailList(pNode pHead, unsigned int key)
{
	assert(pHead);

	unsigned int i = 0;
	pNode pTempHead = pHead;
	pNode pTempBegin = NULL;

	if (pHead == NULL || key == 0)
		return NULL;

	else
	{
		for (i = 0; i < key - 1; ++i)
		{
			if (pTempHead->_pNext != NULL)
			{
				pTempHead = pTempHead->_pNext;
			}
			else
			{
				return NULL;
			}
		}

		pTempBegin = pHead;
		while (pTempBegin->_pNext != NULL)
		{
			pTempHead = pTempHead->_pNext;
			pTempBegin = pTempBegin->_pNext;

		}
		return pTempBegin;
	}
}




void test()
{
	pNode pHead1 = NULL;
	pNode Knum = NULL;

	
	InstallFrontNode(&pHead1, 4);
	InstallFrontNode(&pHead1, 6);
	InstallFrontNode(&pHead1, 0);
	InstallFrontNode(&pHead1, 7);
	InstallFrontNode(&pHead1, 4);
	InstallFrontNode(&pHead1, 3);


	PrintList(pHead1);

	Knum = FindKToTailList(pHead1, 3);
	printf("%d\n", Knum->data);
}


int main()
{
	test();
	return 0;
}

```
