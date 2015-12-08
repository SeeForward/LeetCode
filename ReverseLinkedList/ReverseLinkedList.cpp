//Date:2015-12-03
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
    ListNode* reverseList(ListNode* head) {
    	if(NULL == head || NULL == head->next)
    		return head;

    	ListNode* rHead = head; 
        ListNode* mid = head->next;
        rHead->next = NULL;

        head = mid->next;

        while(head) {
        	mid->next = rHead;
        	rHead = mid;

        	mid = head;

        	head = head->next;
        }

        mid->next = rHead;
        rHead = mid;

        return rHead;
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

	head = Solution().reverseList(&n1);

	while(head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

	return 0;
}



