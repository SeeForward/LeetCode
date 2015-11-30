//Date: 2015.11.13
//Octher:lidengke

#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> nums);
};

vector<vector<int> > Solution::threeSum(vector<int> nums) {
	vector<vector<int> > result;

	sort(nums.begin(), nums.end());
	
	int n = nums.size();
	for(int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
		int low = i + 1;
		int high = n - 1;
		while(low < high) {
			if(nums[i] + nums[low] + nums[high] == 0) {
				vector<int> v;
				v.push_back(nums[i]);
				v.push_back(nums[low]);
				v.push_back(nums[high]);

				result.push_back(v);
				while(low < high && nums[low] == nums[low + 1]) ++low;
				++low;
				while(low < high && nums[high] == nums[high -1]) --high;
				--high;
			} else if(nums[i] + nums[low] + nums[high] < 0) {
				while(low < high && nums[low] == nums[low + 1]) ++low;
				++low;
			} else {
				while(low < high && nums[high] == nums[high - 1]) --high;
				--high;
			}
		}
		while(i < n - 2 && nums[i] == nums[i + 1]) ++i;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	int a[] = {-1, 1, 1, 1, -1, -1, 0, 0, 0, 2};
	vector<int> v(a, a + sizeof(a)/sizeof(a[0]));
	
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl <<"------------------------" << endl;	
	
	Solution s;
	vector<vector<int> > t = s.threeSum(v);

	for(vector<vector<int> >::iterator i = t.begin(); i != t.end(); ++i) {
		copy(i->begin(), i->end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	return 0;
}
