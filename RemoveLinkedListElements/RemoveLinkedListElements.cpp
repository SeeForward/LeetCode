//Date:2015-12-05
//Author:lidengke


#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //去除头部符合条件的节点
        while(head && val == head->val) {
        	head = head->next;
        }

        ListNode* pRet = head;
        if(NULL == pRet)
        	return pRet;

        //去除队列中符合条件的节点
		ListNode* pPrev = pRet;
		ListNode* pCur = pPrev->next;
		while(pCur) {
			if(val == pCur->val){
				//跳过此节点
				pPrev->next = pCur->next;
				//更新节点指针，遍历下一个
				pCur = pCur->next;

			} else {
				//更新节点指针，遍历下一个
				pPrev = pCur;
				pCur = pCur->next;
			}
		}

		return pRet;
    }
};


int main(int argc, char const *argv[])
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	ListNode* head = &n1;
	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	head = Solution().removeElements(&n1, 1);

	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	
	cout << endl;


	return 0;
}