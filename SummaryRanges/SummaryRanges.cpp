//Date:2015-11-29
//Author:lidengke

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> vecStr;

    	stringstream ss;

    	size_t i = 0;
    	while(i < nums.size()) {
    		int first = nums[i];
    		int last = nums[i];
    		size_t steps = 1;
    		
    		while(i < nums.size()) {
    			if(i + steps >= nums.size()) {
    				if(1 == steps)
    					break;
    				steps /= 2;
    			} else if(steps == nums[i + steps] - last) {
    				i += steps;
    				last = nums[i];

    				steps *= 2;
    			} else {
    				if(1 == steps){
    					break;
    				}
    				steps /= 2;
    			}
    		}
    		++i;

    		if(first == last) {
    			ss.str("");
    			ss << first;
    			vecStr.push_back(ss.str());
    		}
    		else {
    			ss.str("");
    			ss << first << "->" << last;
    			vecStr.push_back(ss.str());
    		}
    	}
    	return vecStr;
    }
};


int main(int argc, char const *argv[])
{
	int arr[] = {0,1,2,4,5,7,8,10};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

	vector<string> vecStr = Solution().summaryRanges(v);

	copy(vecStr.begin(), vecStr.end(), ostream_iterator<string>(cout, "  "));
	cout << endl;

	return 0;
}