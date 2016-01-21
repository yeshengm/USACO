/*
ID:mayeshe1
LANG: C++
PROG:contact
*/
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
ifstream fin("contact.in");
ofstream fout("contact.out");

typedef pair<string, int> strPair;
int A, B, N; //length A-B, top N freq
string str;
int sz;
map<string, int> strMap;

bool cmp(strPair a, strPair b) {
	if (a.second > b.second) {
		return true;
	} else if (a.second < b.second) {
		return false;
	} else {
		if (a.first.size() != b.first.size()) {
			return a.first.size() < b.first.size();
		} else {
			return a.first < b.first;
		}
	}
}

int main() 
{
	fin >> A >> B >> N;
	string tmp;
	while (fin >> tmp) {
		str += tmp;
	}
	if (A > B)
		swap(A, B);
	for (size_t i = 0; i < str.size(); ++i) {
		for (size_t len = A; len <= B; ++len) {
			if (i + len > str.size()) {
				break;
			}
			string s;
			for (size_t pos = i; pos < i + len; ++pos) {
				s += str[pos];
			}
			if (strMap.find(s) == strMap.end()) {
				strMap.insert(strPair(s, 1));
			} else {
				strMap[s]++;
			}
		}
	}
	vector<strPair> vec;
	for (map<string, int>::iterator it = strMap.begin(); it != strMap.end(); ++it) {
		vec.push_back(*it);
	}
	sort(vec.begin(), vec.end(), cmp);
	fout << (*vec.begin()).second << endl;
	fout << (*vec.begin()).first;
	int currCnt = 1, cnt = 1;
	for (int i = 1; i < vec.size() && cnt <= N; ++i) {
		if (vec[i].second == vec[i - 1].second) {
			if (currCnt == 6) {
				fout << endl << vec[i].first;
				currCnt = 1;
			} else {
				fout << " " << vec[i].first;
				currCnt++;
			}
		} else {
			currCnt = 1;
			++cnt;
			if (cnt > N) {
				break;
			}
			fout << endl << vec[i].second << endl;
			fout << vec[i].first;
		}
	}
	fout << endl;
	return 0;
}