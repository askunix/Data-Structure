#include"tree_node.h"
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

void CreateTreeNode(pTreeNode &T)
{
	Datatype ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;  //保证是叶结点
	else
	{
		T = (pTreeNode)malloc(sizeof(TreeNode));
		//if (!*T)
		//exit(OVERFLOW); //内存分配失败则退出。
		(T)->_data = ch;//生成结点
		CreateTreeNode(T->_pLeft);//构造左子树
		CreateTreeNode(T->_pRight);//构造右子树    
	}
}



void PrintTreeNode(pTreeNode &T)
{
	//std::cout << "打印" << std::endl;
	if (T == NULL)
		return;
	pTreeNode pcur = T;
	std::stack<pTreeNode> S;
	while (pcur || !S.empty())
	{
		while (pcur)
		{
			std::cout << pcur->_data << "→";
			S.push(pcur);
			pcur = pcur->_pLeft;
		}
		//pcur指向最左边路径的末端

		pTreeNode top = S.top();
		S.pop();
		pcur = top->_pRight;
	}
}





void InOrderPrint(pTreeNode &T)
{
	if (!T)
		return;
	pTreeNode pCur = T;
	stack<pTreeNode> S;

	while (pCur || !S.empty())
	{
		{
			while (pCur)
			{
				S.push(pCur);
				pCur = pCur->_pLeft;
			}

			//末端
			pTreeNode top = S.top();
			cout << top->_data << "→";
			S.pop();
			pCur = top->_pRight;
		}
	}
}



void PostOrderNode(pTreeNode &T)
{
	stack<pTreeNode> S;
	pTreeNode cur = T;
	pTreeNode prev = NULL;

	if (NULL == T)
		return;

	while (cur || !S.empty())
	{
		while (cur)
		{
			S.push(cur);
			cur = cur->_pLeft;
		}

		pTreeNode top = S.top();
		if (top->_pRight == NULL || top->_pRight == prev)
		{
			cout << top->_data << "→";
			prev = top;
			S.pop();
		}

		else
		{
			cur = top->_pRight;
		}

	}
	cout << endl;
}



	/*
void endOrderPrint(pTreeNode &T)
{
	if (NULL == T)
		return;

	stack<pTreeNode> S;
	pTreeNode pCur = T;
	pTreeNode pLastVisit = NULL;

	while (pCur)
	{
		S.push(pCur);
		pCur = pCur->_pLeft;
	}

	while (!S.empty())
	{
	    pCur = S.top();
		S.pop();


		if (pCur->_pRight == NULL || pCur->_pRight == pLastVisit)
		{
			cout << pCur->_data << "→";
			pLastVisit = pCur;
		}

		else //pCur->_pLeft == pLastVisit
		{
			S.push(pCur);
			//进入右字树，且右字树肯定不为空
			pCur = pCur->_pRight;
			while (pCur)
			{
				S.push(pCur);
				pCur = pCur->_pLeft;
			}
		}
	}
	cout << endl;

}
#endif

*/




void FloorPrintNode(pTreeNode &T)
{
	if (NULL == T)
		return;
	queue<pTreeNode> Q;
	
	Q.push(T);

	while (!Q.empty())
	{
		cout << Q.front()->_data << "→";

		if (Q.front()->_pLeft)
			Q.push(Q.front()->_pLeft);

		if (Q.front()->_pRight)
			Q.push(Q.front()->_pRight);

		Q.pop();
	}
}



int GetDeep_DG(pTreeNode &T)    //递归求树高
{
	int leftDeep, rightDeep, max;
	if (NULL != T)
	{
		leftDeep = GetDeep_DG(T->_pLeft);
		rightDeep = GetDeep_DG(T->_pRight);
		max = leftDeep > rightDeep ? leftDeep : rightDeep;
		return max + 1;
	}
	else
		return 0;
}



////非递归创建二叉树
//
//
//pTreeNode CreateNode(char* data)  //创建一个节点
//{
//	pTreeNode temp = (pTreeNode)malloc(sizeof(TreeNode));
//	temp->_data = *data;
//	temp->_pLeft = NULL;
//	temp->_pRight = NULL;
//	return temp;
//}
//
//
//pTreeNode CreateBiTreeNonRecur(char* str)
//{
//	TreeNode* stack[1000];
//	int top = 0;
//	if (*str == '\0')
//	{
//		cout << "创建一个空的二叉树";
//		return NULL;
//	}
//	TreeNode* root = NULL;
//	TreeNode* tempRoot = NULL; //当前指向节点
//	TreeNode* temp = NULL;
//	root = CreateNode(str);
//	tempRoot = root;
//	while (*str != '\0')
//	{
//		str++;
//		if (*(str - 1) != '#')  //建树过程中如果一直未碰到@符号，则持续建立左子树
//		{					//并将节点压入栈中
//			stack[top++] = tempRoot;
//			if (*str != '#')    //判断当前节点是不是@节点，如果是的左子树为空
//			{
//				temp = CreateNode(str);
//				tempRoot->_pLeft = temp;
//				tempRoot = temp;
//			}
//			else
//			{
//				tempRoot->_pRight = NULL;
//			}
//
//		}
//		if (*(str - 1) == '#' && top >0)  //若前一个节点是@，则出栈，建立右子树
//		{
//			tempRoot = stack[--top];
//			if (*str != '#')//判断当前节点是不是@节点，如果是的右子树为空
//			{
//				temp = CreateNode(str);
//				tempRoot->_pLeft = temp;
//				tempRoot = temp;
//			}
//			else
//				tempRoot->_pRight = NULL;
//		}
//	}
//	return root;
//}




int GetNodeNumber(pTreeNode &T)
{
	if (T)
	{
		return GetNodeNumber(T->_pLeft) + GetNodeNumber(T->_pRight) + 1;
	}
	return 0;
}



int GetLeafNodeNumber(pTreeNode &T)
{
	if (NULL == T)
		return 0;

	if (T->_pLeft == NULL && T->_pRight == NULL)
		return 1;

	int leftNum = GetLeafNodeNumber(T->_pLeft);
	int rightNum = GetLeafNodeNumber(T->_pRight);
	return leftNum + rightNum;
}




int GetNodeFromKLevel(pTreeNode &T, int K)
{
	if (NULL == T || K < 0)
		return 0;

	if (0 == K)
		return 1;

	int leftNode = GetNodeFromKLevel(T->_pLeft, K - 1);
	int rightNode = GetNodeFromKLevel(T->_pRight, K - 1);
	
	return leftNode + rightNode;
}



//判断一个节点是否在一个二叉树中
//bool IsHasNode(pTreeNode &T)
//{
//
//} 


//
//
//int _Height(pTreeNode T, int &distance)
//{
//	if (NULL == T) 
//		return 0;
//
//	int leftH = _Height(T->_pLeft);
//	int rightH = _Height(T->_pRight);
//}
//
//
//
//int GetFarLength(pTreeNode &T)
//{
//	int distence = -1;
//	_Height(T, distance);
//	return distance;
//}