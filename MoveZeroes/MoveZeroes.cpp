//Date:2015-11-22
//Author:lidengke


#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
	void moveZeroes(vector<int>& nums) {
		vector<int>::iterator zeroPos = nums.begin();
		while(zeroPos != nums.end() && *zeroPos != 0)
			++zeroPos;

		vector<int>::iterator beginPos = zeroPos;
		vector<int>::iterator endPos = zeroPos;

		while(endPos != nums.end()) {

			for(beginPos = endPos; beginPos != nums.end(); ++beginPos){
				if(*beginPos != 0)
					break;
			}
			
			for(endPos = beginPos; endPos != nums.end(); ++endPos)
			{
				if(*endPos == 0)
					break;
			}
			
			copy(beginPos, endPos, zeroPos);

			zeroPos += endPos - beginPos;
		}
		
		while(zeroPos != nums.end()) {
			*zeroPos = 0;
			++zeroPos;
		}
	}
};


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6, 0,1,2,0};
	// int arr[] = {0,1,0,0,3,12,0,0,0,0,0,0,0,0,0};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));

	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	Solution().moveZeroes(nums);

	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
	cout << endl;


	return 0;
}