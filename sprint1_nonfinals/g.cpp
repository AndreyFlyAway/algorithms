#include <iostream>
#include <string>

using namespace std;

string ToBinary(int number) {
	if (number == 0) { return "0";}
	if (number == 1) { return "1";}
	string res;
	
	int d = 2;
	while(number != 0) {
		res = to_string(number % 2).append(res);
		number = number / 2;
	}
	return res;
}

void print(const string &result) {
	cout << result << endl;
}


int main() {
	int number;
	cin >> number;
	print(ToBinary(number));
}
