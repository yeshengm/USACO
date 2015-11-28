/*
ID: mayeshe1
LANG: C++
PROG: prefix
*/
#include "iostream"
#include "cstdio"
#include "string"
#include "fstream"
#include "cstring"
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

string elem[205];
int len[205];
int elemCnt;
string str;
int strLen;
bool mark[200005];

void check(int i, int j) {
	if (i + len[j] > strLen || mark[i - 1 + len[j]] == true) 
		return;
	for (int k = 0; k < len[j]; ++k) {
		if (elem[j][k] != str[i + k])
			return;
	}
	mark[i - 1 + len[j]] = true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	string tmp;
	for (int i = 0; i <= 200; ++i) {
		fin >> tmp;
		if (tmp == ".")
			break;
		else {elem[i] = tmp; ++elemCnt;}
	}
	while (fin >> tmp) {
		str += tmp;
	}
	for (int i = 0; i < elemCnt; ++i) 
		len[i] = (elem[i]).size();
	strLen = str.size();
	for (int i = 0; i < strLen; ++i) {
		for (int j = 0; j < elemCnt; ++j) {
			if (i == 0 || (i >= 1 && mark[i - 1] == true))
				check(i, j);
		}
	}
	for (int i = strLen - 1; i >= 0; --i)
		if (mark[i] == true) {
			fout << i + 1 << endl;
			return 0;
		}
	fout << '0' << endl;
	return 0;
}