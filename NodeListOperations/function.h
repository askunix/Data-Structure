#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
#define DataType int

struct Node
{
	DataType data;
	struct Node* _pNext;
};

typedef struct Node Node;
typedef Node *pNode;

pNode InitNodeList(pNode *pHead);//��ʼ��

pNode BuyNewNode(DataType data);//�½��ڵ�

void InsertNodeByFrontToTail(pNode *pHead, DataType data);//ͷ�巨

void PrintNodeProntToTail(pNode pHead);//�����ӡ

void InserttNodeByTailToFront(pNode *pHead, DataType data);//β�巨

pNode ReceiveNodeList(pNode pHead);//��ת����һ�㷽��

pNode ReceiveNodeList_DG(pNode pHead);//��ת�������ݹ�ʵ��

pNode MeryTwoSortNodeChangeOneSortNode(pNode pHead1, pNode pHead2);//�ϲ���������������һ�㷽��

pNode MeryTwoSortNodeChangeOneSortNode_DG(pNode pHead1, pNode pHead2);//�ϲ����������������ݹ�ʵ��

void BubbleSortNodeList(pNode pHead);//�������򡪡�ð�ݷ�ʵ��

pNode SearchMIdNode(pNode pHead);//�����м�ڵ㡪������ָ�뷨

pNode FindLastKNode(pNode pHead, int key);//�ҵ�������K���ڵ�

void InsertNotIntoKHead(pNode pos, DataType data);// ��ͷ���ǰ����data

pNode FindDataInNodeList(pNode pHead, DataType k);//Ѱ��������dataΪK�Ľڵ�

void DeleteLastKNode(pNode pHead, int key);//ɾ��������K���ڵ�

void DeleteNotTailNode(pNode pos);//ɾ��������ķ�β���

void GetCircleForJoseph(pNode pHead);//����Լɪ��

void GetJosephCircle(pNode pHead, size_t K);//������ʵ��Լɪ��

void GetCircleForList(pNode pHead);//�����������

pNode isHaveCircle(pNode pHead);//�ж������Ƿ����

int GetCircleLength(pNode pHead);//�󻷵ĳ���

pNode GetCircleIntoNode(pNode pHead);//�󻷵���ڵ�

pNode pFrontNode(pNode pHead);//���������һ���ڵ�

pNode pTailNode(pNode pHead); //�����������һ���ڵ�

void InsertNotHead(pNode pos, DataType data);// ��ͷ���ǰ����data

#endif






//// ɾ��������ķ�β���
//void DeleteNotTailNode(pNode pos);
//// ��ͷ���ǰ����data
//void InsertNotHead(pNode pos, DataType data);
//// ������ʵ��Լɪ��
//pNode JosephCircle(pNode pHead, size_t M);
//// �����������--ǰ��ָ��
//pNode ReverseList(pNode pHead);
//// �����������--ͷ�巨
//pNode ReverseList(pNode pHead);
//// ����������м���---Ҫ���ܱ���������
//pNode FindMidNode(pNode pHead);

//��ν��л��������ɵ�������������� 

//����ж������������Ƿ��н��㣿����ҵ���һ���ཻ�Ľڵ㣿
//���������ж����������Ƿ��л������һ���л�һ��û�����϶����ཻ��
//���������û�л����ж������б��β���Ƿ���ȣ�
//����������л����ж�һ�������ϵ�Z���Ƿ�����һ�������ϡ�


