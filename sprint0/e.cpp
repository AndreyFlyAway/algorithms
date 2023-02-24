#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Если ответ существует, верните вектор из двух элементов
// Если нет - то верните пустой вектор
vector <int> TwoSum(const vector <int> &sortedArr, int targetSum) {
	vector <int> res;
	int f = 0;
	int l = sortedArr.size() - 1;
	while(f != l) {
		int sum = sortedArr[f] + sortedArr[l];
		if (sum == targetSum) {
			res.push_back(sortedArr[f]);
			res.push_back(sortedArr[l]);
			break;
		} else if (sum > targetSum) {
			l--;
		} else {
			f++;
		}
	}
	return res;
}

void print(const vector <int> &result) {
	if (result.size() != 2)
		cout << "None" << endl;
	else
		cout << result[0] << " " << result[1] << endl;
}

int main() {
	int n, targetSum;
	cin >> n;
	vector <int> sortedArr(n);
	for (int i = 0; i < n; ++i)
		cin >> sortedArr[i];
	cin >> targetSum;
	print(TwoSum(sortedArr, targetSum));
}
