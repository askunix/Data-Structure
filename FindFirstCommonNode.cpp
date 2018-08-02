/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) 
    {
        int length1 = FindLength(pHead1);
        int length2 = FindLength(pHead2);
        
        if(length1 <= length2){
            pHead2 = GoNSteps(pHead2, length2 - length1);
        }
        else{
            pHead1 = GoNSteps(pHead1, length1 - length2); 
        }
        while(pHead1 != pHead2){
            pHead1 = pHead1 -> next;
            pHead2 = pHead2 -> next;
        }
        return pHead1;
    }
    
    //计算链表长度
    int FindLength(ListNode* pHead){
        int length = 0;
        while(pHead){
            ++length;
            pHead = pHead -> next;
        }
        return length;
    }
    
    //前进N个结点
    ListNode* GoNSteps(ListNode* pHead, int n){
        while(n--){
            pHead = pHead -> next;
        }
        return pHead;
    }
    
};
