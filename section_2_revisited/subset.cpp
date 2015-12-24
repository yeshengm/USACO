/*
ID: mayeshe1
LANG: C++
PROG: subset
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");

long long dp[50][2000];
int N;

int main()
{
	fin >> N;
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= i*(i-1)/2; ++j) {
			if (j - i >= 0) dp[i][j - i] += dp[i - 1][j];
			else dp[i][i - j] += dp[i - 1][j];
			dp[i][j + i] += dp[i - 1][j];
		}
	}
	fout << dp[N][0] / 2 << endl;
	return 0;
}