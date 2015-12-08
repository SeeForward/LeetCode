//Date:2015-12-06
//Author:lidengke

#include <iostream>

using namespace std;


class Solution {
public:
	int countPrimes(int n) {
		if(n <= 1)
			return 0;

		int sum = 0;
		for(int i = 2; i < n; ++i) {
			if(isPrime(i))
				++sum;
		}
		return sum;
	}
private:
	//判断一个大于1的整数是否为质数
	bool isPrime(int n) {
		for(int i = 2; i <= n / 2; ++i) {
			if(n % i == 0)
				return false;
		}
		return true;
	}
};


int main(int argc, char const *argv[])
{
	
	cout << Solution().countPrimes(4) << endl;

	return 0;
}