/*
ID: mayeshe1
LANG: C++
PROG: prefix
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
char subStr[201][11]; int len[201], N;
char s[200001]; int L;
bool dp[200001];
int strlen(char a[]) {
	int i = 0;
	while (a[i] != '\0') ++i;
	return i;
}
void init() {
	while (1) {
		fin >> subStr[N];
		if (subStr[N][0] != '.') { len[N] = strlen(subStr[N]); ++N; }
		else break;
	}
	char ch;
	fin.get();
	while (fin.get(ch)) {
		if (ch == '\n') continue;
		else s[L++] = ch;
	}
	s[L] = 0;
}
int main()
{
	init();
	dp[0] = true;          //dp[i] 以i为起点的字符串是否存在
	for (int i = 0; i <= L; ++i) {
		if (dp[i]) {
			for (int j = 0; j < N; ++j) {
				int next = i + len[j];
				if (next > L || dp[next] == true)
					continue;
				bool flag = true;
				int p;
				for (p = 0; p < len[j]; ++p) {
					if (s[p + i] != subStr[j][p]) {
						flag = false;
						break;
					}
				}
				if (flag) dp[p + i] = true;
			}
		}
	}
	for (int i = L; i >= 0; --i) {
		if (dp[i]) {
			fout << i << endl;
			return 0;
		}
	}
}