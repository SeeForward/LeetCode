//Date:2015 11 12
//Outher:lidengke

#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums);

private:
	vector<int> 	_v;
	vector<vector<int> >  _t;
};

vector<vector<int> > Solution::threeSum(vector<int>& nums) {
	_v = nums;
	sort(_v.begin(), _v.end());

	pair<vector<int>::iterator, vector<int>::iterator> mid = equal_range(_v.begin(), _v.end(), 0);
	
	vector<int> tmpV;
	if(mid.second - mid.first > 2) {
		tmpV.push_back(0);
		tmpV.push_back(0);
		tmpV.push_back(0);
		_t.push_back(tmpV);
	}
	
	if(mid.first == _v.begin() || mid.second == _v.end())
		return _t;

	vector<int>::iterator x = _v.begin();

	while(x < mid.second) {
		vector<int>::iterator y = x + 1;
		while(y < mid.second) {
			if(find(mid.second, _v.end(), -(*x + *y)) != _v.end()) {
				tmpV.clear();
				tmpV.push_back(*x);
				tmpV.push_back(*y);
				tmpV.push_back(-(*x + *y));
				_t.push_back(tmpV);
			}
			while(y + 1 < mid.second && *y == *(y+1)) ++y;
			++y;
		}
		while(x + 1 < mid.second && *x == *(x + 1)) ++x;
		++x;
	}

	while(x < _v.end()) {
		vector<int>::iterator y = x + 1;
		while(y < _v.end()) {
			if(find(_v.begin(), mid.first, -(*x + *y)) != mid.first) {
				tmpV.clear();
				tmpV.push_back(-(*x + *y));
				tmpV.push_back(*x);
				tmpV.push_back(*y);
				_t.push_back(tmpV);
			}
			while(y + 1 < _v.end() && *y == *(y + 1)) ++y;
			++y;
		}
		while(x + 1 < _v.end() && *x == *(x + 1)) ++x;
		++x;
	}

	return _t;
}

int main(int argc, char const *argv[])
{
	int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0,-2};
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
