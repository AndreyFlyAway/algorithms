#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector <double> MovingAverage(const vector <int> &arr, int windowSize) {
	vector <double> res;
	double sum = accumulate(arr.begin(), arr.begin() + windowSize, 0);
	res.push_back(sum/windowSize);
	int n = arr.size() - windowSize + 1;
	for(int i = 0 ; i < n - 1; ++i) {
		sum -= arr[i];
		sum += arr[i+windowSize];
		res.push_back(sum/windowSize);
	}
	return res;
}

void print(const vector <double> &result) {
	for (double x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n, windowSize;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> windowSize;
	print(MovingAverage(arr, windowSize));
}
