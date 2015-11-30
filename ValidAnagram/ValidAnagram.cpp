//Date:2015-11-24
//Auther:lidengke

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if(s.size() != t.size())
			return false;

		vector<int> _times(26, 0);

		for(size_t i = 0; i < s.size(); ++i) {
			++_times[s[i] - 'a'];
			--_times[t[i] - 'a'];
		}

		for(size_t i = 0; i < _times.size(); ++i) {
			if(_times[i])
				return false;
		}

		return true;
	}
};

int main(int argc, char const *argv[])
{
	string s("cat");
	string t("car");

	cout << Solution().isAnagram(s, t) << endl;

	return 0;
}