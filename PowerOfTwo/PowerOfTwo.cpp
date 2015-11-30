//Date:2015-11-26
//Author:lidengke

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*if(n <= 0)
            return false;
        
        int t = 1;
        int x = n;

        while(x > 256){
            x >>= 8;
            t *= 256;
        }

        while(x != 1) {

            x >>= 1;
            t *= 2;
        }

        if(n == t)
            return true;
        else
            return false;*/

        if(n <= 0)
            return false;
        int x

        if(0xff000000 & n) {

        }
        if(0x00ff0000 & n) {

        }
        if(0x0000ff00 & n) {

        }
        if (0x00000ff & n) {

        }
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().isPowerOfTwo(1073741824) << endl;
    return 0;
}