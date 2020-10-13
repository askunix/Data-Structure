#ifndef __TREE_NODE__
#define __TREE_NODE__

#include<iostream>
#include<string>
#include<stack>
#define Datatype char

typedef struct TreeNode
{
	Datatype _data;
	struct TreeNode *_pLeft;
	struct TreeNode *_pRight;
}TreeNode, *pTreeNode;



void CreateTreeNode(pTreeNode &T); //前序遍历——递归法创建二叉树

void PrintTreeNode(pTreeNode &T); //前序遍历

void InOrderPrint(pTreeNode &T); //中序遍历

void endOrderPrint(pTreeNode &T);  //后序遍历  方法一

void PostOrderNode(pTreeNode &T); //后序遍历  方法二

void FloorPrintNode(pTreeNode &T); //层序遍历

int GetDeep_DG(pTreeNode &T); //求数的深度

//pTreeNode CreateBiTreeNonRecur(char* str); //非递归创建二叉树

int GetNodeNumber(pTreeNode &T); //求整个二叉树的节点数目

int GetLeafNodeNumber(pTreeNode &T); //求二叉树叶子节点数目

int GetNodeFromKLevel(pTreeNode &T, int K); //返回第K层的节点数目

//bool IsHasNode(pTreeNode &T); //判断一个节点是否在一个二叉树中





#endif