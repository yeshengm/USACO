/*
ID: mayeshe1
LANG: C++
PROG: money
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");

int N, val, v[31];
long long dp[31][10005];

int main()
{
	fin >> N >> val;
	for (int i = 1; i <= N; ++i)
		fin >> v[i];
	dp[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= val; ++j) {
			for (int k = 0; j + k * v[i] <= val; ++k) {
				dp[i][j + k * v[i]] += dp[i - 1][j];
			}
		}
	}
	fout << dp[N][val] << endl;
	return 0;
}