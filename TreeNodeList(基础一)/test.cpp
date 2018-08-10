#include"tree_node.h"
#include<iostream>

using namespace std;


void test()
{
	pTreeNode Tree;       //ABD##E##C#F##
	cout << "创建二叉树，请输入：" << endl;
	CreateTreeNode(Tree);
	cout << endl;

	cout << "前序打印二叉树" << endl;
	PrintTreeNode(Tree);
	cout << endl;

	cout << "中序打印二叉树" << endl;
	InOrderPrint(Tree);
	cout << endl;

	cout << "后序遍历二叉树" << endl;
	//endOrderPrint(Tree);
	PostOrderNode(Tree);
	cout << endl;

	cout << "层序遍历二叉树" << endl;
	FloorPrintNode(Tree);
	cout << endl;

	cout << "输出高度" << endl;
	cout << GetDeep_DG(Tree) << endl;
	cout << endl;

	cout << "节点个数" << endl;
	cout << GetNodeNumber(Tree) << endl;
	cout << endl;

	cout << "叶子节点个数" << endl;
	cout << GetLeafNodeNumber(Tree) << endl;
	cout << endl;

	int K = 2;
	cout << "二叉树第"<< K << "节点个数" << endl;
	cout << GetNodeFromKLevel(Tree, K) << endl;
	cout << endl;


}



int main()
{
	test();
	return 0;
}
