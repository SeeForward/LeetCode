//Date:2015-11-14
//Auther:lidengke

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};

void print(ListNode head) {

}

int main(int argc, char const *argv[])
{
	
	return 0;
}