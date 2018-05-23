#### Describe：
> 已知两个链表head1和head2各自有序，请把它们合并成一个链表依然有序。结果链表要包含head1和head2的所有节点，即使节点值相同。

- 递归写法：

```C++
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node *Next;
}Node, *pNode;


void InitNode(pNode pHead)     //初始化
{
    pHead = NULL;
}


void PrintNode(pNode pHead)    //打印
{
    while (pHead)
    {
        printf("%d -> " ,pHead->data);
        pHead = pHead->Next;
    }
    printf("NULL\n");
}


pNode BuyNewNode(int data)     //新建节点
{
    pNode temp = (pNode)malloc(sizeof(Node));
    if (temp)
    {
        temp->data = data;
        temp->Next = NULL;
    }
    return temp;
}


void PushFront(pNode *pHead, int data)
{
    pNode tempNode = NULL;
    assert(pHead);
    if (NULL == *pHead)
        *pHead = BuyNewNode(data);
    else
    {
        tempNode = BuyNewNode(data);
        tempNode->Next = *pHead;
        *pHead = tempNode;
    }
}


pNode TwoOrderList(pNode pList1, pNode pList2)
{
    pNode tempHead = NULL;
    if (pList1 == NULL)
        return pList2;
    if (pList2 == NULL)
        return pList1;
    if (pList1->data < pList2->data)
    {
        tempHead = pList1;
        tempHead->Next = TwoOrderList(pList1->Next, pList2);
    }
    else    //(pList1->data > pList2->data)
    {
        tempHead = pList2;
        tempHead->Next = TwoOrderList(pList1, pList2->Next);
    }
    return tempHead;
}


int main()
{
    pNode pHead1 = NULL;
    pNode pHead2 = NULL;
    pNode pNewHead = NULL;

    InitNode(pHead1);
    InitNode(pHead2);

    PushFront(&pHead1, 12);
    PushFront(&pHead1, 10);
    PushFront(&pHead1, 8);
    PushFront(&pHead1, 6);
    PushFront(&pHead1, 1);

    PushFront(&pHead2, 11);
    PushFront(&pHead2, 9);
    PushFront(&pHead2, 6);
    PushFront(&pHead2, 3);
    PushFront(&pHead2, -9);

    pNewHead = TwoOrderList(pHead1, pHead2);


    printf("Node1: ");
    PrintNode(pHead1);

    printf("\nNode2: ");
    PrintNode(pHead2);

    printf("\nNewNode: ");
    PrintNode(pNewHead);
    //

    return 0;

}
```

- 非递归写法：

```
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *_pNext;
}Node, *pNode;


void InitNode(pNode pHead)
{
    pHead = NULL;
}

pNode BuyNewNode(DataType data)
{
    pNode tempNode = NULL;
    tempNode = (pNode)malloc(sizeof(Node));
    if (tempNode)
    {
        tempNode->data = data;
        tempNode->_pNext = NULL;
    }
    return tempNode;
}

void PushFront(pNode *pHead, DataType data)
{
    assert(pHead);
    pNode tempNode = NULL;
    if (NULL == *pHead)
    {
        *pHead = BuyNewNode(data);
    }
    else
    {
        tempNode = BuyNewNode(data);
        tempNode->_pNext = *pHead;
        *pHead = tempNode;
    }
}

void printNode(pNode pHead)
{
    while (pHead)
    {
        printf("%d -> ", pHead->data);
        pHead = pHead->_pNext;
    }
    printf("NULL");
}

pNode TwoOrderListToOne(pNode pList1, pNode pList2)
{
    pNode pTail = NULL;
    pNode NewHead = NULL;

    if (pList1 == NULL)
        return pList2;
    else if (pList2 == NULL)
        return pList1;

    else
    {
        if (pList1->data < pList2->data)       //确定头
        {
            NewHead = pList1;
            pList1 = pList1->_pNext;        
        }
        else
        {
            NewHead = pList2;
            pList2 = pList2->_pNext;
        }

        pTail = NewHead;       //pTail保存头指针
        while (pList1 && pList2)
        {
            if (pList1->data <= pList2->data)
            {
                pTail->_pNext = pList1;
                pList1 = pList1->_pNext;    //指向链表的第二个结点
            }
            else
            {
                pTail->_pNext = pList2;
                pList2 = pList2->_pNext;
            } 
            pTail = pTail->_pNext;
        }
        if (NULL == pList1)
        {
            pTail->_pNext = pList2;
        }
        else if(NULL == pList2)
        {
            pTail->_pNext = pList1;
        }
        return NewHead;
    }
}

void test()
{
    pNode pHead1 = NULL;
    pNode pHead2 = NULL;
    pNode pNewHead = NULL;

    InitNode(pHead1);
    InitNode(pHead2);
    InitNode(pNewHead);

    PuhFront(&pHead1, 10);
    PushFront(&pHead1, 8);
    PushFront(&pHead1, 7);
    PushFront(&pHead1, -2);

    PushFront(&pHead2, 16);
    PushFront(&pHead2, 13);
    PushFront(&pHead2, 11);
    PushFront(&pHead2, 6);
    PushFront(&pHead2, -16);
    pNewHead = TwoOrderListToOne(pHead1, pHead2);

    printf("pHead1: ");
    printNode(pHead1);
    printf("\nPhead2: ");
    printNode(pHead2);
    printf("\npNewNode: ");
    printNode(pNewHead);
}

int main()
{
    test();
    return 0;
}
```
