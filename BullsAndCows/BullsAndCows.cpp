//Date:2015-11-17
//Author:lidengke


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess);
};

string Solution::getHint(string secret, string guess) {
	vector<int> secretTimes(10, 0);
	vector<int> guessTimes(10, 0);

	int BullsCount = 0;
	for(int i = 0; i < secret.size(); ++i) {
		if(secret[i] == guess[i]) {
			++BullsCount;
		} else {
			++secretTimes[secret[i] - '0'];
			++guessTimes[guess[i] - '0'];
		}
	}

	int CowsCount = 0;
	for(int i = 0; i < 10; ++i) {
		CowsCount += secretTimes[i] > guessTimes[i] ? guessTimes[i] : secretTimes[i];
	}
	

	stringstream ss;
	ss << BullsCount << 'A' << CowsCount << 'B';

	return ss.str();
}

int main(int argc, char const *argv[])
{
	cout << Solution().getHint("1123", "0111") << endl;

	return 0;
}