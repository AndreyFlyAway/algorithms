#include <iostream>
#include <string>
#include <ctype.h>


#include <algorithm>
#include  <utility>
#include  <vector>

using namespace std;

bool toCheck(char& c) {
	bool res = false;
	if (c >= 'a' && c <= 'z') {
		res = true;
	} else if (c >= 'A' && c <= 'Z') {
		res = true;
	} else if (c >= '0' && c <= '9') {
		res = true;
	}
	return res;
}

bool IsPalindrome(const string &line) {
	if (line.empty()) {return false;}
	int left = 0;
	int right = line.length() - 1;
	if (right == left) {return isalpha(line[0]);}

	bool res = false;
	while (left < right)
	{
		while (left < right && isalpha(line[left]) == false ){++left;}
		while (left < right && isalpha(line[right]) == false){--right;}
		if (tolower(line[left]) == tolower(line[right])){
			if (left == right) {
				res = isalpha(line[right]);
			} else {
				res = true;
			}
		} else {
			res = false;
			break;
		}
		
		++left;
		--right;
	}
	return res;
}

void print(bool result) {
	if (result)
		cout << "True";
	else
		cout << "False";
	cout << endl;
}

int check_tc(int tc, const string& line, bool expected) {
	if (IsPalindrome(line) == expected) {
		cout << "SUCCESS#" << tc << ": for line '" << line << "'" << endl;
		return 1;
	} else {
		cout << "FAILED#" << tc << ": for line '" << line << "'" << endl;
		return 0;
	}
}


int main() {
	vector<pair<string,bool>> tcs;
	/*1*/tcs.emplace_back("mamam", true); 
	/*2*/tcs.emplace_back("mamaman", false); 
	/*3*/tcs.emplace_back("mama,mam", true); 
	/*4*/tcs.emplace_back("A man, a plan, a canal: Panama", true); 
	/*5*/tcs.emplace_back("      A man, a plan, a canal: Panama", true); 
	/*6*/tcs.emplace_back("      A man, a plan, a canal: Panama NO", false); 
	/*7*/tcs.emplace_back("      a", true); 
	/*8*/tcs.emplace_back("      ", false); 
	/*9*/tcs.emplace_back(".", false); 
	/*10*/tcs.emplace_back(".kekek as sa kekek        :.", true); 
	/*11*/tcs.emplace_back("..:..", false); 
	/*12*/tcs.emplace_back(".", false); 
	/*12*/tcs.emplace_back("a", true); 
	/*13*/tcs.emplace_back("aa", true); 
	/*14*/tcs.emplace_back("aa///", true); 
	/*15*/tcs.emplace_back("a        aa///aa", true); 
	/*15*/tcs.emplace_back("aabbbbbbaa", true); 

	// /*2*/tcs.emplace_back("zo", false); 
	// /*3*/tcs.emplace_back("A man, a plan, a canal: Panama ", true); 

	for(int i = 0 ; i < tcs.size() ; ++i) {
		auto p = tcs[i];
		check_tc(i+1, p.first, p.second);
	}
}

// int main() {
// 	string line;
// 	getline(cin, line);
// 	print(IsPalindrome(line));
// }
