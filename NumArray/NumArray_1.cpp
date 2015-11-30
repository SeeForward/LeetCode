//Date: 2015-11-18
//Auther: lidengke


//error: time limit exceeded


#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) : _nums(nums) { }

    int sumRange(int i, int j) {
    	while(1) {

    		while(j) {
    			first /= 10;
    			times *= 10;
    		}

    		int last = 
    		int y = j / 10;
    	}
        return sum;
    }
private:
	int getSum(int pos, int distance) {
		int i = 0;
		if(_sums[i].find(pos) == _sums.end())
			_sums[i][pos] = accumulate(_nums.begin() + pos, _nums.begin() + pos + distance, 0);

		return _sums[i][pos];
	}

	int 
private:
	vector<int>& 			_nums;
	vector<map<int, int> >  _sums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);


int main(int argc, char const *argv[])
{
	int arr[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,,1,1,1,1,1,1,1,1};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	NumArray numArray(nums);

	cout << numArray.sumRange(50, 150) << endl;
	cout << numArray.sumRange(0, 100) << endl;
	cout << numArray.sumRange(100, 200) << endl;
	cout << numArray.sumRange(0, 5) << endl;

	return 0;
}