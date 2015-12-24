/*
ID: mayeshe1
LANG: C++
PROG: inflate
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("inflate.in");
ofstream fout("inflate.out");

#define max(x, y) ((x > y) ? x : y)
const int MAXNUM = 10001;
struct prob {
	int p, t;
	double avg;
} pro[MAXNUM];
int T, N, dp[MAXNUM];
void init() {
	fin >> T >> N;
	for (int i = 1; i <= N; ++i) {
		fin >> pro[i].p >> pro[i].t;
		pro[i].avg = (double) pro[i].p / pro[i].t;
	}
}
void getdp() {
	for (int i = 1; i <= N; ++i) {
		for (int j = pro[i].t; j <= T; ++j) {
			dp[j] = max(dp[j], dp[j - pro[i].t] + pro[i].p);
		}
	}
}

int main()
{
	init();
	getdp();
	fout << dp[T] << endl;
	return 0;
}