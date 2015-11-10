//Date:2015 11 09
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
	void findTwoNegate(int value, vector<int>::iterator begin, vector<int>::iterator last);
	vector<int> createThreeElementVector(int first, int second, int third);
	
private:
	vector<int> 	_v;
	vector<vector<int> >  _t;
};



vector<vector<int> > Solution::threeSum(vector<int>& nums) {
	_v = nums;
	sort(_v.begin(), _v.end());

	pair<vector<int>::iterator, vector<int>::iterator> i = equal_range(_v.begin(), _v.end(), 0);
	

	if(i.second - i.first > 2) {
		vector<int> tmpV = createThreeElementVector(0, 0, 0);
		_t.push_back(tmpV);
	}
	
	if(i.first == _v.begin() || i.second == _v.end())
		return _t;

	vector<int>::iterator pos = _v.begin();

	int repeat = *pos;
	while(pos < i.first) {
		pair<vector<int>::iterator, vector<int>::iterator> tmpP = equal_range(i.first, _v.end(), 0-*pos);
		vector<int>::iterator max = tmpP.second;

		findTwoNegate(*pos, i.first, max);

		repeat = *pos;
		++pos;
		while(repeat == *pos)
			++pos;
	}

	pos = i.second;

	while(pos < _v.end()) {
		pair<vector<int>::iterator, vector<int>::iterator> tmpP = equal_range(_v.begin(), i.second, 0-*(pos));
		vector<int>::iterator min = tmpP.first;

		findTwoNegate(*pos, min, i.first);
		
		repeat = *pos;
		++pos;
		while(repeat == *pos)
			++pos;
	}

	return _t;
}

void Solution::findTwoNegate(int value,  vector<int>::iterator begin, vector<int>::iterator last){
	vector<int> tmpV;

	while(begin < last) {
		vector<int>::iterator pos = begin;
		vector<int>::iterator tmp = pos++;

		while(pos < last) {
			if(*tmp + *pos + value == 0) {
				tmpV = createThreeElementVector(*tmp, *pos, value);
				_t.push_back(tmpV);
			}
			while(pos + 1 != last && *pos == *(pos + 1))
				++pos;
			++pos;

		}
		while(begin + 1 != last && *begin == *(begin + 1))
			++begin;
		++begin;
	}
}

vector<int> Solution::createThreeElementVector(int first, int second, int third){
	vector<int> tmp;
	tmp.push_back(first);
	tmp.push_back(second);
	tmp.push_back(third);

	sort(tmp.begin(), tmp.end());

	return tmp;
}

int main(int argc, char const *argv[])
{
	int a[] = {-1, 1, 1, 1, -1, -1, 0,0,0};
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