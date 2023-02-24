#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int GetScore(const vector <char> &values, int k) {
    int res = 0;
    vector<int> symbolsCount(10,0);
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] != '.') {
            symbolsCount[values[i] - '0']++;
        }
    }
    for(int i = 0 ; i < symbolsCount.size() ; ++i) {
        if (symbolsCount[i] != 0 && symbolsCount[i] <= 2*k) {
            res++;
        }
    }
    return res;
}


void print(int result) {
    cout << result << endl;
}

void printMatrix(vector<char> &values) {
    for (int i = 0; i < values.size() ; i = i+4) {
        for(int j = 0 ; j < 4 ; ++j) {
            cout << values[i+j] << " ";
        } 
        cout << endl;
    }
	cout << endl;
}

int check_tc(int tc, const vector<char> &values, int k, int expected) {
    int res = GetScore(values, k);
    if (res != expected) {
        cout << "FAILED #" << tc <<  " values = " <<  res << " vs " << expected << endl;
        return 1;
    }
	cout << "SUCCESS #" << tc << endl;
    return 0;
}

int main() {
    vector<pair<vector<char>, int>> tcs;
    vector<int> expected;
    /*1*/ tcs.emplace_back(vector<char> {'1','2','3','1',
                                         '2','.','.','2',
                                         '2','.','.','2',
                                         '2','.','.','2',
                                         }, 3);
          expected.emplace_back(2);

    /*2*/ tcs.emplace_back(vector<char> {'1','1','1','1',
                                         '1','1','1','1',
                                         '1','1','1','1',
                                         '1','1','1','1',
                                         }, 1);
          expected.emplace_back(0);

    /*3*/ tcs.emplace_back(vector<char> {'1','1','2','2',
                                         '3','3','4','4',
                                         '5','5','5','5',
                                         '6','6','7','7',
                                         }, 2);
          expected.emplace_back(7);

    /*4*/ tcs.emplace_back(vector<char> {'1','1','1','2',
                                         '2','2','4','4',
                                         '5','5','5','5',
                                         '5','5','7','5',
                                         }, 3);
          expected.emplace_back(4);

    /*5*/ tcs.emplace_back(vector<char> {'5','5','5','2',
                                         '2','2','4','4',
                                         '5','5','5','5',
                                         '5','1','7','5',
                                         }, 3);
          expected.emplace_back(4);

    /*6*/ tcs.emplace_back(vector<char> {'.','.','.','.',
                                         '.','6','6','.',
                                         '.','.','7','6',
                                         '.','8','.','5',
                                         }, 1);
          expected.emplace_back(3);

    /*7*/ tcs.emplace_back(vector<char> {'.','.','.','.',
                                         '.','6','6','.',
                                         '.','.','7','6',
                                         '.','8','.','5',
                                         }, 3);
          expected.emplace_back(4);

    /*8*/ tcs.emplace_back(vector<char> {'3','3','3','3',
                                         '.','6','6','3',
                                         '.','3','7','6',
                                         '3','8','3','5',
                                         }, 4);
          expected.emplace_back(5);

    /*9*/ tcs.emplace_back(vector<char> {'3','3','3','3',
                                         '.','6','6','3',
                                         '.','3','7','6',
                                         '3','8','3','5',
                                         }, 3);
          expected.emplace_back(4);

    /*10*/ tcs.emplace_back(vector<char> {'3','0','0','3',
                                         '.','6','6','0',
                                         '.','0','7','6',
                                         '0','8','0','5',
                                         }, 3);
          expected.emplace_back(6);

    /*11*/ tcs.emplace_back(vector<char> {'3','0','0','3',
                                         '0','6','6','0',
                                         '.','0','7','6',
                                         '0','8','0','5',
                                         }, 3);
          expected.emplace_back(5);

    /*12*/ tcs.emplace_back(vector<char> {'3','0','0','3',
                                         '0','6','6','0',
                                         '.','0','7','6',
                                         '0','8','0','5',
                                         }, 10);
          expected.emplace_back(6);


    /*13*/ tcs.emplace_back(vector<char> {'.','.','.','.',
                                         '.','.','.','.',
                                         '.','.','.','.',
                                         '.','.','.','.',
                                         }, 1);
          expected.emplace_back(0);
    
    /*14*/ tcs.emplace_back(vector<char> {'1','1','1','1',
                                         '1','1','1','1',
                                         '1','1','1','1',
                                         '1','1','1','1',
                                         }, 4);
          expected.emplace_back(0);
    
    /*15*/ tcs.emplace_back(vector<char> {'2','2','9','3',
                                         '4','9','1','2',
                                         '4','8','3','6',
                                         '7','4','5','.',
                                         }, 1);
          expected.emplace_back(7);
    
    /*16*/ tcs.emplace_back(vector<char> {'8','1','7','7',
                                         '5','3','2','1',
                                         '6','6','3','3',
                                         '8','2','1','3',
                                         }, 1);
          expected.emplace_back(5);

    for(int i = 0 ; i < tcs.size() ; ++i) {
		auto p = tcs[i];
		check_tc(i+1, p.first, p.second, expected[i]);
	}
}

// int main() {
// 	int k;
// 	cin >> k;
// 	// vector <vector <char> > matrix(4, vector <char> (4));
//     vector <char> values(16, '.');
// 	for (int i = 0; i < values.size(); ++i)
// 		cin >> values[i];
//     printMatrix(values);
// 	print(GetScore(values, k));
// }
