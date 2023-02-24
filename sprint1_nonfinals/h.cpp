#include <iostream>
#include <string>
#include <vector>

using namespace std;

string GetSum(const string &firstNumber, const string &secondNumber) {
	if (firstNumber.empty()) {
		return secondNumber;
	}
	if (secondNumber.empty()) {
		return firstNumber;
	}
	int frss_i = firstNumber.length() - 1;
	int secs_i = secondNumber.length() - 1;
	vector <char> res;

	int count = max(secs_i, frss_i);
	int prev = 0;
	while(frss_i >= 0 || secs_i >= 0 || prev != 0) {
		char v1 = frss_i >= 0 ?  firstNumber[frss_i] : '0';
		char v2 = secs_i >= 0 ?  secondNumber[secs_i] : '0';
		int v = (v1 == '1')  + (v2 == '1') + prev;
		prev = v >= 2;
		char symb = (v % 2 == 0) ? '0' : '1';

		res.push_back(symb);
		frss_i--;
		secs_i--;
	}
	string str_reult;
	for(int i = res.size() - 1; i >= 0 ; --i) {
		str_reult.push_back(res[i]);
	}

	return str_reult;
}

void print(const string &result) {
	cout << result << endl;
}

int main() {
	string firstNumber, secondNumber;
	cin >> firstNumber >> secondNumber;
	print(GetSum(firstNumber, secondNumber));
}
