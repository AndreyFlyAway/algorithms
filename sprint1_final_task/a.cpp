#include <iostream>
#include <vector>
#include <algorithm>

#include <chrono>
using namespace std::chrono;

using namespace std;

vector <int> GetNearestZero(const vector <int> &places) {
    int placesSize = places.size();
    vector <int> res (placesSize, 0);
    if (placesSize <= 1) { return res; } // краевой случай
    int firtZero = -1;
    int lastZero = -1;
    for(int i = 0 ; i < placesSize ; ++i) {
        if (places[i] == 0) { firtZero = i ; continue; } // запоминаю ноль слева
        if (lastZero <= i) {
            // ищу следующий ноль, вычисляю расстояние до ближайшего соседа с нулем
            lastZero = -1;
            int j;
            for(j = i+1 ; j < placesSize; ++j) {
                if (places[j] == 0) {
                    lastZero = j;
                    break;
                }
            }
        }
        if (firtZero >= 0 && lastZero > 0 ) {
            res[i] = min(i - firtZero, lastZero - i);
        } else if (firtZero >= 0 && lastZero < 0 ) {
            res[i] = i - firtZero ;
        } else if  (firtZero < 0 && lastZero > 0 ) {
            res[i] = lastZero - i;
        }
    }
    return res;
}


void print(const vector <int> &result) {
	for(int i = 0 ; i < result.size() ; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int check_tc(int tc, const vector<int> &value, const vector<int> & expected) {
    vector<int> res = GetNearestZero(value);
    if (res.size() != expected.size()) {
        cout << "FAILED #" << tc << ": size of result array is not equal expected - " <<  res.size() << " vs " << expected.size() << endl;
        return 1;
    }
    for(int i = 0 ; i < res.size() ; ++i) {
        if (res[i] != expected[i]) {
            cout << "FAILED #" << tc << ": value for index " << i << " are unequal - " <<  res[i] << " vs " << expected[i] << endl;
            return 1;
        }
    }
	cout << "SUCCESS #" << tc << endl;
    return 0;
}

int main() {
    vector<pair<vector<int>,vector<int>>> tcs;
    // /*1*/tcs.emplace_back(vector<int> {0, 7, 9, 4, 8}, vector<int> {0, 1, 2, 3, 4}); 
    // /*2*/tcs.emplace_back(vector<int> {0, 7, 9, 4, 0}, vector<int> {0, 1, 2, 1, 0}); 
    // /*3*/tcs.emplace_back(vector<int> {0, 0, 7, 9, 4, 0, 0, 0,}, vector<int> {0, 0, 1, 2, 1, 0, 0, 0}); 
    // /*4*/tcs.emplace_back(vector<int> {0, 0, 7, 9, 4, 0, 0, 0,}, vector<int> {0, 0, 1, 2, 1, 0, 0, 0}); 
    // /*5*/tcs.emplace_back(vector<int> {0, 1, 0, 9, 0, 1, 0, 1,}, vector<int> {0, 1, 0, 1, 0, 1, 0, 1}); 
    // /*6*/tcs.emplace_back(vector<int> {0, 1, 2, 3, 0, 0, 1, 1, 0, 0}, vector<int> {0, 1, 2, 1, 0, 0, 1, 1, 0, 0}); 
    // /*7*/tcs.emplace_back(vector<int> {0, 1, 2, 3, 4, 5, 0, 0, 0, 1, 2 ,4, 0,0,0,0,0,0,0,0}, vector<int> {0, 1, 2, 3, 2, 1, 0, 0, 0, 1, 2 ,1, 0,0,0,0,0,0,0,0}); 
    // /*8*/tcs.emplace_back(vector<int> {0,0,0,0,0,0}, vector<int> {0,0,0,0,0,0}); 
    // /*9*/tcs.emplace_back(vector<int> {0,0,0,1,0,0}, vector<int> {0,0,0,1,0,0}); 
    // /*10*/tcs.emplace_back(vector<int> {0,0,2,1,3,0,0,0,0,0,0,1}, vector<int> {0,0,1,2,1,0,0,0,0,0,0,1}); 
    // /*11*/tcs.emplace_back(vector<int> {0,0,2,1,3,0,0,0,0,0,0,1}, vector<int> {0,0,1,2,1,0,0,0,0,0,0,1}); 
    // /*12*/tcs.emplace_back(vector<int> {0,0,1,1,0,0,0,0,0,0,0,1}, vector<int> {0,0,1,1,0,0,0,0,0,0,0,1}); 
    // /*13*/tcs.emplace_back(vector<int> {1,2,1,1,3,4}, vector<int> {0,0,0,0,0,0}); 
    // /*14*/tcs.emplace_back(vector<int> {5,4,3,2,1,0}, vector<int> {5,4,3,2,1,0}); 
    // /*15*/tcs.emplace_back(vector<int> {0,1,2,3,4,5,4,3,2,1,0}, vector<int> {0,1,2,3,4,5,4,3,2,1,0}); 
    // /*16*/tcs.emplace_back(vector<int> {10,9,8,7,6,5,4,3,2,1,0}, vector<int> {10,9,8,7,6,5,4,3,2,1,0}); 
    // /**/tcs.emplace_back(vector<int> {1}, vector<int> {0}); 
    // /**/tcs.emplace_back(vector<int> {0}, vector<int> {0}); 

    // for(int i = 0 ; i < tcs.size() ; ++i) {
	// 	auto p = tcs[i];
	// 	check_tc(i+1, p.first, p.second);
	// }

    // stress test;
    static int n = 1000000;
    vector<int> values (n, 0);
    vector<int> expected (n, 0);
    for (int i = 0 ; i < n / 2 ; ++i) {
        values[i] = i+1;
        expected[i] = n / 2 - i;
    } 
    
    // print(values);
    // print(expected);
    auto time_start = high_resolution_clock::now();
    check_tc(0, values, expected);
    auto time_finish = high_resolution_clock::now();
    auto time_span = duration_cast<duration<double>>(time_finish - time_start);
    std::cout << time_span.count() << " seconds\n";
}


// int main() {
// 	int n;
// 	cin >> n;
// 	vector <int> places(n);
// 	for (int i = 0; i < n; ++i)
// 		cin >> places[i];
// 	print(GetNearestZero(places));
// }
