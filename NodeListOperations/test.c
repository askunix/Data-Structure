#include"function.h"

void test()
{
	pNode pHead1 = NULL;
	pNode pHead2 = NULL;
	pNode pNewHead = NULL;
	pNode pHead3 = NULL;
	pNode pSortNode = NULL;
	pNode LastKNum = 0;
	pNode pReverseNode = NULL;
	pNode pR = NULL;
	pNode pHead4 = NULL;
	pNode pCirclieNode = NULL;
	size_t CircleLength = 0;
	pNode pIntoCircleNode = NULL;
	pNode pHead5 = NULL;
	pNode JueNode = NULL;
	pNode pHead6 = NULL;
	pNode pDelNode = NULL;
	pNode pInsertNode = NULL;
	pNode pH = NULL;

	InsertNodeByFrontToTail(&pHead1, 9);
	InsertNodeByFrontToTail(&pHead1, 8);
	InsertNodeByFrontToTail(&pHead1, 6);
	InsertNodeByFrontToTail(&pHead1, 5);
	InsertNodeByFrontToTail(&pHead1, 2);
	InsertNodeByFrontToTail(&pHead1, 1);

	PrintNodeProntToTail(pHead1);

	printf("\n����ķ�ת����ԭ:\n");
	pReverseNode = ReceiveNodeList(pHead1);     //��ת
	PrintNodeProntToTail(pReverseNode);
	
	pR = ReceiveNodeList_DG(pReverseNode);      //��ת
	PrintNodeProntToTail(pR);

	pHead1 = pR;
	printf("\npHead1: ");
	PrintNodeProntToTail(pHead1);          //��ԭpHead1

	printf("\n");

	InserttNodeByTailToFront(&pHead2, 2);
	InserttNodeByTailToFront(&pHead2, 3);
	InserttNodeByTailToFront(&pHead2, 4);
	InserttNodeByTailToFront(&pHead2, 5);
	InserttNodeByTailToFront(&pHead2, 6);
	InserttNodeByTailToFront(&pHead2, 7);
	
	printf("pHead2: ");
	PrintNodeProntToTail(pHead2);

	printf("\n������������ĺϲ�:\n");
	pNewHead = MeryTwoSortNodeChangeOneSortNode_DG(pHead1, pHead2);
	PrintNodeProntToTail(pNewHead);


	//�½���������3
	InsertNodeByFrontToTail(&pHead3, 9);
	InsertNodeByFrontToTail(&pHead3, 4);
	InsertNodeByFrontToTail(&pHead3, 5);
	InsertNodeByFrontToTail(&pHead3, 7);
	InsertNodeByFrontToTail(&pHead3, 4);
	InsertNodeByFrontToTail(&pHead3, 0);
	InsertNodeByFrontToTail(&pHead3, 3);

	printf("\npHead3: ");
	PrintNodeProntToTail(pHead3);

	printf("\n����õ�����3��");
	BubbleSortNodeList(pHead3);
	PrintNodeProntToTail(pHead3);

	printf("\npHead1�м�ڵ㣺%d\n", (SearchMIdNode(pHead1)->data));
	printf("\npNewHead�м�ڵ㣺%d\n", (SearchMIdNode(pNewHead)->data));

	printf("\n���ҵ�����K���ڵ�: ");
	LastKNum = FindLastKNode(pNewHead, 2);
	if (LastKNum != NULL)
		printf("%d\n", LastKNum->data);
	else
		printf("û���ҵ�\n");

	printf("\nɾ��������K���ڵ�\n");
	DeleteLastKNode(pNewHead, 3);

	//����һ����������4
	InsertNodeByFrontToTail(&pHead4, 9);
	InsertNodeByFrontToTail(&pHead4, 8);
	InsertNodeByFrontToTail(&pHead4, 6);
	InsertNodeByFrontToTail(&pHead4, 5);
	InsertNodeByFrontToTail(&pHead4, 2);
	InsertNodeByFrontToTail(&pHead4, 1);
	InsertNodeByFrontToTail(&pHead4, 3);
	InsertNodeByFrontToTail(&pHead4, 0);
	InsertNodeByFrontToTail(&pHead4, 7);
	
	printf("\n��ӡ����4��\n");
	PrintNodeProntToTail(pHead4);

	printf("\n�����������\n");
	GetCircleForList(pHead4);
	printf("����OK\n");

	pCirclieNode = isHaveCircle(pHead4);
	if (pCirclieNode == NULL)
		printf("������\n");
	else
		printf("����\n");

	printf("\n�󻷵ĳ��ȣ�");
	//PrintNodeProntToTail(pHead4);

	CircleLength = GetCircleLength(pHead4);
	printf("%d", CircleLength);

	printf("\n�󻷵���ڣ�");
	pIntoCircleNode = GetCircleIntoNode(pHead4);
	printf("%d\n", pIntoCircleNode->data);

	//����һ������pHead5��    ͷ�巨���쵥����
	InsertNodeByFrontToTail(&pHead5, 9);
	InsertNodeByFrontToTail(&pHead5, 8);
	InsertNodeByFrontToTail(&pHead5, 7);
	InsertNodeByFrontToTail(&pHead5, 6);
	InsertNodeByFrontToTail(&pHead5, 5);
	InsertNodeByFrontToTail(&pHead5, 4);
	InsertNodeByFrontToTail(&pHead5, 3);
	InsertNodeByFrontToTail(&pHead5, 2);
	InsertNodeByFrontToTail(&pHead5, 1);

	printf("\nԼɪ������:\n");
	//���컷
	GetCircleForJoseph(pHead5);
	printf("����OK\n");

	//PrintNodeProntToTail(pHead5);

	//Լɪ��
	GetJosephCircle(pHead5, 4);

	printf("��������6\n");

	InsertNodeByFrontToTail(&pHead6, 6);
	InsertNodeByFrontToTail(&pHead6, 5);
	InsertNodeByFrontToTail(&pHead6, 4);
	InsertNodeByFrontToTail(&pHead6, 3);
	InsertNodeByFrontToTail(&pHead6, 2);

	PrintNodeProntToTail(pHead6);
	printf("\nɾ�������� 3 ���ڵ������Ϊ��\n");
	DeleteLastKNode(pHead6, 3);

	PrintNodeProntToTail(pHead6);
	printf("\n");

	PrintNodeProntToTail(pHead6);
	printf("ɾ����β�ڵ� 3 :\n");
	pDelNode = FindDataInNodeList(pHead6, 3);
	DeleteNotTailNode(pDelNode);
	PrintNodeProntToTail(pHead6);

	printf("\n��ͷ�ڵ� 5 ǰ�Ĳ���:\n");
	PrintNodeProntToTail(pHead6);

	pInsertNode = FindDataInNodeList(pHead6, 5);
	
	InsertNotHead(pInsertNode, 99);
	PrintNodeProntToTail(pHead6);
	printf("\n");
}

int main()
{
	test();
	return 0;
}