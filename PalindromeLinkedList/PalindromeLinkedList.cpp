//Date:2015-11-25
//Author:lidengke

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(NULL == head || NULL == head->next)
    		return true;
    	
    	ListNode* sHead = head;
    	head = head->next;
    	sHead->next = NULL;

    	ListNode* end = head->next;
    	
    	while(end) {
    		ListNode* tmp = head;
    		head = head->next;
    		tmp->next = sHead;
    		sHead = tmp;


    		end = end->next;
    		if(NULL == end) {
    			sHead = sHead->next;
    			break;
    		}
    		end = end->next;
    	}

    	while(head && sHead) {
    		if(head->val != sHead->val)
    			return false;
    		head = head->next;
    		sHead = sHead->next;
    	}

    	return true;

    }
};

int main(int argc, char const *argv[])
{
	ListNode x1(0);

	ListNode x2(1);

	//ListNode x3(1);

	//ListNode x4(0);

	x1.next = &x2;
	//x2.next = &x3;
	//x3.next = &x4;

	cout << Solution().isPalindrome(&x1) << endl;
	
	return 0;
}