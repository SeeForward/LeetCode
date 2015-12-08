//Date:2015-12-01
//Author:lidengke

#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<int>::iterator rear = nums.begin();

        while(rear != nums.end() && rear < nums.begin() + k + 1) {
        	if(_setI.find(*rear) != _setI.end())
        		return true;
        	else
        		_setI.insert(*rear);

        	++rear;
        }

        vector<int>::iterator head = nums.begin();
        while(rear < nums.end()) {
        	_setI.erase(*head);

        	if(_setI.find(*rear) != _setI.end())
        		return true;
        	else
        		_setI.insert(*rear);
        	++head;
        	++rear;
        }
        return false;
    }
private:
	set<int> _setI;
};


int main(int argc, char const *argv[])
{
	// int arr[] = {1,2,3,4,5,6,7,8,9,0,1};
	int arr[] = {-1, -1};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

	cout << Solution().containsNearbyDuplicate(v, 10) << endl;

	return 0;
};