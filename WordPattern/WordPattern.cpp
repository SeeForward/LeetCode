//Date:2015-11-22
//Author:lidengke




#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {

    	if(pattern.empty() && !str.empty() ||
    		str.empty() && !pattern.empty())
    		return false;

    	size_t bigenPos = 0;
        for(size_t i = 0; i < pattern.size(); ++i) {
        	char c = pattern[i];

        	size_t pos = str.find(' ', bigenPos);
        	string s = str.substr(bigenPos, pos - bigenPos);
        	bigenPos = pos + 1;

        	if(i == pattern.size() -1 && pos != string::npos || 
        		pos == string::npos && i != pattern.size() - 1)
        		return false;

        	map<string, char>::iterator iter = _mapSC.find(s);
        	if(iter != _mapSC.end()) {
        		if(iter->second != c)
        			return false;
        	} else {
        		_mapSC[s] = c;
        	}

        	map<char, string>::iterator itr = _mapCS.find(c);
        	if(itr != _mapCS.end()) {
        		if(itr->second != s)
        			return false;
        	} else {
        		_mapCS[c] = s;
        	}
        }

        return true;
    }
private:
	map<string, char> _mapSC;
	map<char, string> _mapCS;
};


int main(int argc, char const *argv[])
{
	string p = "";

	string s = "beef";

	cout << Solution().wordPattern(p, s) << endl;

	return 0;
}











