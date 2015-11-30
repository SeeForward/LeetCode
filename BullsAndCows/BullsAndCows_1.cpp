//Date:2015-11-17
//Author:lidengke

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
	int CowsCount = 0;
	for(int i = 0; i < secret.size(); ++i) {
		if(secret[i] == guess[i]) {
			++BullsCount;
		} else {
			int pos = secret[i] - '0';
			if(guessTimes[pos]) {
				++CowsCount;
				--guessTimes[pos];
			} else {
				++secretTimes[pos];
			}

			pos = guess[i] - '0';
			if(secretTimes[pos]) {
				++CowsCount;
				--secretTimes[pos];
			} else {
				++guessTimes[pos];
			}
		}
	}

	stringstream ss;
	ss << BullsCount << 'A' << CowsCount << 'B';

	return ss.str();
}

int main(int argc, char const *argv[])
{
	cout << Solution().getHint("1122", "2211") << endl;

	return 0;
}