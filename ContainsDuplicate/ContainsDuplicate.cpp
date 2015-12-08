//Date:2015-12-03
//Author: lidengke

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
    		if(_setI.find(*iter) != _setI.end())
    			return true;
    		else
    			_setI.insert(*iter);
    	}   
    	return false; 
    }
private:
	set<int> _setI;
};

int main(int argc, char const *argv[])
{
	
	return 0;
}