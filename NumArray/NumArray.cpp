//Date:2015-11-17
//Author:lidengke


//error: time limited exceeded


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class NumArray {
public:
    NumArray(vector<int> &nums) : _nums(nums){
    }

    int sumRange(int i, int j) {
        return accumulate(_nums.begin() + i, _nums.begin() + j + 1, 0);
    }
private:
	vector<int>& _nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);


int main(int argc, char const *argv[])
{
	int arr[] = {-2, 0, 3, -5, 2, -1};
	vector<int> nums(arr, arr + sizeof(arr)/sizeof(arr[0]));
	NumArray numArray(nums);

	cout << numArray.sumRange(0, 2) << endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;

	return 0;
}