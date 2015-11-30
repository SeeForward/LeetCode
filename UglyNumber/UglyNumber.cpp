//Date:2015-11-23
//Auther:lidengke
#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;

        int isDiv = true;
        while(isDiv) {
            isDiv = false;
            if(num % 2 == 0) {
                num /= 2;
                isDiv = true;
            }
            if(num % 3 == 0) {
                num /= 3;
                isDiv = true;
            }
            if(num % 5 == 0) {
                num /= 5;
                isDiv = true;
            }
            if(num == 1)
                return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}