//Date:2015-12-05
//Author:lidengke

#include <iostream>
#include <sstream>
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isHappy(int n) {
    	ostringstream os;
    	os << n;
    	
    	//记录每次循环到小于10的数字
    	string str;
    	vector<int> v;
    	v.resize(10);

    	while(1) {
    		str = os.str();

    		n = accumulate(str.begin(), str.end(), 0, deal);
    		if(n < 10) {
	    		if(1 == n)
	    			return true;
	    		else {
	    			//如果此小于10的数字已经循环到达过，则失败
	    			if(1 == v[n])
	    				return false;
	    			else
	    				v[n] = 1;
	    		}
    		}
    		//清空流
    		os.str("");
    		os << n;
    		
    	}
    }
private:
	static int deal(int sum, int x) {
		int n = x - static_cast<int>('0');
		return sum + n * n;
	}	
};


int main(int argc, char const *argv[])
{
	
	cout << Solution().isHappy(2) << endl;

	return 0;
}