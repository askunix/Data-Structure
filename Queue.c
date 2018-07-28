#include<stdio.h>
#include<stdlib.h>



#define False 0
#define True 1
typedef int elemtype;


typedef struct Node
{
	elemtype _Data;
	struct Node *_pNext;
}Node;

typedef struct Queue
{
	Node *Front;
	Node *Rear;
}Queue;



void InitQueue(Queue *q)
{
	q->Front = q->Rear = (Node *)malloc(sizeof(Node));
	if (q->Front == NULL)
		return;
	q->Front->_pNext = NULL;
}


int isEmpty(Queue *q)
{
	if (q->Front == q->Rear)
		return True;
	else
		return False;
}


void Enqueue(Queue *q, elemtype data)
{
	Node *ret = (Node*)malloc(sizeof(Node));
	if (ret == NULL)
		exit(0);

	q->Rear->_Data = data;
	q->Rear->_pNext = ret;
	q->Rear = ret;
}




void DisposeQueue(Queue *q)
{
	Node *frontTmp = q->Front;
	while (frontTmp != q->Rear)
	{
		printf("%d    ", frontTmp->_Data);
		frontTmp = frontTmp->_pNext;
	}
	printf("\n");
}


int DelQueue(Queue* q)
{
	Node* frontTemp = NULL;
	if (isEmpty(q))
		exit(0);
	frontTemp = q->Front;
	elemtype data = q->Front->_Data;
	q->Front = q->Front->_pNext;
	free(frontTemp);
	return data;
}


int main()
{
	int i = 0;
	int x = 0;
	Queue q;
	InitQueue(&q);
	for (i = 0; i <= 5; i++)
	{
		Enqueue(&q, i);
	}
	DisposeQueue(&q);
	x = DelQueue(&q);
	printf("%d\n", x);
	DisposeQueue(&q);
	
	return 0;
}



