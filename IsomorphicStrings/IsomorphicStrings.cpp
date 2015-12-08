//Date:2015-12-03
//Author:lidengke

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	map<char, char> mapCC1;
    	map<char, char> mapCC2;

		for(size_t i = 0; i < s.size(); ++i) {

			map<char, char>::iterator iter = mapCC1.find(s[i]);
			if(iter != mapCC1.end()){
				if(iter->second != t[i])
					return false;
			} else {
				mapCC1[s[i]] = t[i];
			}

			iter = mapCC2.find(t[i]);
			if(iter != mapCC2.end()){
				if(iter->second != s[i])
					return false;
			} else {
				mapCC2[t[i]] = s[i];
			}
		}

    	return true;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().isIsomorphic("ab", "aa") << endl;
	
	cout << Solution().isIsomorphic("foo", "bar") << endl;

	cout << Solution().isIsomorphic("paper", "title") << endl;

	cout << Solution().isIsomorphic("add", "egg") << endl;

	return 0;
}