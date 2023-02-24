#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetWeatherRandomness(const vector <int> &t) {
	int res = 0;
	int l = t.size();
	
	if (l == 0 || l == 1) return l;
	if (l > 3) {
		if (t[0] > t[1]) res++;
		if (t[l - 1] > t[l - 2]) res++;
		for(int i = 1 ; i < (l - 1) ; ++i) {
			if (t[i-1] < t[i] && t[i+1] < t[i])
				res++;
		}

	} else {
		res = t[1] > t[0];
	}
	return res;
}

void print(int result) {
	cout << result << endl;
}

int main() {
	int n;
	cin >> n;
	vector <int> temperatures(n);
	for (int i = 0; i < n; ++i)
		cin >> temperatures[i];
	print(GetWeatherRandomness(temperatures));
}
