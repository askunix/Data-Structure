#include <iostream>  
#include <list>  
using namespace std;

struct ListNode{      //链表定义
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

// head不带头结点  
// k 旋转个数  
// 最后不满k个不用旋转  
ListNode *ReverseKGroup(ListNode *head, int k) {
	if (head == NULL || k < 2){
		return head;
	}
	//添加头结点  
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *pre, *cur, *tail;
	pre = dummy;
	// 分组旋转的第一个节点即旋转后的尾节点  
	tail = head;
	// 当前节点  
	cur = head;
	int count = 0;
	// 链表节点个数  
	while (cur != NULL){
		cur = cur->next;
		count++;
	}
	// 旋转次数  
	int rCount = count / k;
	// 分组旋转下标  
	int index = 0;
	// 旋转  
	while (rCount){
		// 分组旋转  
		index = k - 1;
		while (index){    //先删除  
			cur = tail->next;
			tail->next = cur->next;
	
			cur->next = pre->next;     //再插入  
			pre->next = cur;
			index--;
		}
		pre = tail;
		tail = tail->next;
		rCount--;
	}//while  
	return dummy->next;
}


int main(){
	//创建链表用于测试
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	ListNode *head = new ListNode(0);
	head->next = NULL;
	ListNode *node;
	ListNode *pre = head;
	
	for (int i = 0; i < 8; i++){
		node = new ListNode(A[i]);
		node->next = NULL;
		pre->next = node;
		pre = node;
	}

	head = ReverseKGroup(head->next, 3);   //翻转K处理

	while (head != NULL){          //打印链表
		cout << head->val << " -> ";
		head = head->next;
	}
	cout <<"NULL" <<endl;
	return 0;
}
