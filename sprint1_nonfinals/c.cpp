#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> GetNeighbours(const vector <vector <int> > &matrix, int row, int col) {
	vector <int> res;
	vector <int> r_n = {row-1, row+1, row, row}; 
	vector <int> c_n = {col, col, col-1, col+1}; 
	for (int i = 0 ; i < 4 ; ++i) {
		int r =  r_n[i]; 
		int c =  c_n[i]; 
		if (r >= 0 && c >= 0 && (r < matrix.size()) && (c < matrix[0].size())) {
			res.push_back(matrix[r][c]);
		}
	}
	std::sort(res.begin(), res.end());
	return res;
}

void print(const vector <int> &result) {
	for (int x : result)
		cout << x << " ";
	cout << endl;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > matrix(n, vector <int> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> matrix[i][j];
	int row, col;
	cin >> row >> col;
	print(GetNeighbours(matrix, row, col));
}
