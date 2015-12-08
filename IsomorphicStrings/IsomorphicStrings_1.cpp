//Date:2015-12-06
//Author:lidengke

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //存储对应字符
        char m1[256] = {0};
        char m2[256] = {0};

        for(size_t i = 0; i < s.size(); ++i) {
            
            if(m1[s[i]] == 0 && m2[t[i]] == 0) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
                continue;
            }

            if(m1[s[i]] == t[i] && m2[t[i]] == s[i]) {
                continue;
            }

            return false;
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
