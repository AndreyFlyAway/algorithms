#include <iostream>

using namespace std;

bool IsPowerOfFour(int number) {
	int val_diff;
	bool res = false;
	while(number > 0) {
		val_diff = number % 4;
		number = number / 4;
	}
	if (number == 0 && val_diff == 1) {
		res = true;
	} else {
		res = false;
	}
	cout << val_diff <<endl;
	cout << number <<endl;
	return res;
}

void print(bool result) {
	if (result)
		cout << "True";
	else
		cout << "False";
	cout << endl;
}

int main() {
	int number;
	cin >> number;
	print(IsPowerOfFour(number));
}
