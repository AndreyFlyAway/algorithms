#include <iostream>
#include <vector>

using namespace std;

// Если ответ существует, верните вектор из двух элементов
// Если нет - то верните пустой вектор
vector <int> TwoSum(const vector <int> &arr, int targetSum) {
	vector <int> res; 
	for(int i = 0 ; i < arr.size() - 1 ; ++i){
		for(int j = i+1 ; j < arr.size() ; ++j){
			int sum = arr[j] + arr[i];
			if (sum == targetSum) {
				res.push_back(arr[j]);
				res.push_back(arr[i]);
				return res;
			}
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
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> targetSum;
	print(TwoSum(arr, targetSum));
}
