#include <iostream>
using namespace std;
 
/*BST的结点*/
typedef struct node
{
    int key;
    struct node *lChild, *rChild;
}Node, *BST;
 
/*在给定的BST中插入结点，其数据域为element, 使之称为新的BST*/
bool BSTInsert(BST &p, int element)
{
    if(NULL == p) // 空树
    {
        p = new Node;
        p->key = element;
        p->lChild = p->rChild = NULL;
        return true;
    }
 
//    if(element == p->key) // BST中不能有相等的值,不注释掉会屏蔽掉相同的树
//        return false;
 
    if(element < p->key)  // 递归
        return BSTInsert(p->lChild, element);
    else
        return BSTInsert(p->rChild, element);
}
 
 
 
/*先序遍历*/
void preOrderTraverse(BST T)
{
    if(T)
    {
        cout << T->key << " ";
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
}
 
/*中序遍历*/
void inOrderTraverse(BST T)
{
    if(T)
    {
        inOrderTraverse(T->lChild);
        cout << T->key << " ";
        inOrderTraverse(T->rChild);
    }
}
/*后序遍历*/
void postOrderTraverse(BST T)
{
    if(T)
    {
        inOrderTraverse(T->lChild);
        inOrderTraverse(T->rChild);
        cout << T->key << " ";
    }
}
int main()
{
    int a[13] = {4, 5, 2, 1, 0, 9, 3, 7, 6, 8,5,4,7};
    int n = 13;
    BST T;
    T = NULL;
    int i;
    for(i = 0; i < n; i++)
    {
        BSTInsert(T, a[i]);
    }
    inOrderTraverse(T);
    cout << endl;
 
 
    return 0;
}
