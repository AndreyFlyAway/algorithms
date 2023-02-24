#include <iostream>
#include <string>
#include <algorithm>
#include  <utility>
#include  <vector>
#include <ctype.h>

using namespace std;

string GetLongestWord(const string &line) {
	int l = line.length();
	if (line.empty()) return line;
	if (line.length() == 1 && line[0] != ' ') return line;
	int start_pos = 0;

	int max_len = 0;
	for(int i = 0, start_l = 0, end_l = 0 ; i < l ; ++i) {
		while(i < l && line[i] == ' ') {++i;} ; start_l = i;
		while(i < l && line[i] != ' ') {end_l = i; ++i;}
		int l_m = end_l - start_l + 1;
		if (l_m > max_len) {
			max_len = l_m;
			start_pos = start_l;
		}
	}
	return line.substr(start_pos, max_len);
}

void print(const string &result) {
	cout << result << endl << result.length() << endl;
}

void check_tc(int tc_num, string line, string expected) {
	auto s = GetLongestWord(line);
	if(s != expected) {
		cout << "FAIL#" << tc_num << ": " << "for string '" << line << "' '" << expected << "' != '" << s << "'" << endl;
	} else {
		cout << "SUCCESS#" << tc_num << ": " << "for string '" << line << "' function returns: '" << s << "'" << endl;
	}
	return;
}

int main() {
	// int n;
	// cin >> n;
	// string line;
	// getline(cin, line);
	// getline(cin, line);
	// print(GetLongestWord(line));


	vector<pair<string,string>> tcs;
	/*1*/tcs.emplace_back("test case1 its", "case1");
	/*2*/tcs.emplace_back(" case1 ", "case1");
	/*3*/tcs.emplace_back(" wt", "wt");
	/*4*/tcs.emplace_back(" a ", "a");
	/*5*/tcs.emplace_back(" 12345678 ", "12345678");
	/*6*/tcs.emplace_back(" 123456789AB a ", "123456789AB");
	/*7*/tcs.emplace_back(" a 123456789AB", "123456789AB");
	/*8*/tcs.emplace_back(" a 123456789AB a ", "123456789AB");
	/*9*/tcs.emplace_back(" a a a v a s a v a s v a s a ", "a");
	/*10*/tcs.emplace_back("a a a v a s a v a s v a s a ", "a");
	/*11*/tcs.emplace_back(" asda  ", "asda");
	/*12*/tcs.emplace_back(" asda as ", "asda");
	/*13*/tcs.emplace_back(" asda as 1234567", "1234567");
	/*14*/tcs.emplace_back("frog jumps from river", "jumps");
	/*15*/tcs.emplace_back(" ", "");
	/*16*/tcs.emplace_back("a", "a");
	/*17*/tcs.emplace_back("i love segment tree", "segment");
	/*18*/tcs.emplace_back("    i love     segment tree      ", "segment");
	for(int i = 0 ; i < tcs.size() ; ++i) {
		auto p = tcs[i];
		check_tc(i+1, p.first, p.second);
	}
}
