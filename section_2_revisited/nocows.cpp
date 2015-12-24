/*
ID: mayeshe1
LANG: C++
PROG: nocows
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
int N, K;

long long a[101][202];

long long dp(int k, int n) {
	if (a[k][n] != -1) return a[k][n];
	if (k == 1 && n == 1) return 1;
	else if (k == 1) return 0;
	if (k == 0 || n == 0) return 0;
	long long tmp = 0;
	for (int i = 1; i < k - 1; ++i) {
		for (int j = 1; j <= n - 2; ++j) {
			tmp += dp(k-1, n-1-j) * dp(i, j);
		}
	}
	tmp *= 2;
	for (int i = 1; i <= n - 2; ++i) {
		tmp += dp(k - 1, n - 1 - i) * dp(k - 1, i);
	}
	return a[k][n] = tmp % 9901;
}

int main()
{   
	fin >> N >> K;
	for (int i = 0; i <= K; ++i)
		for (int j = 0; j <= N; ++j)
			a[i][j] = -1;
	fout << dp(K, N) << endl;
	return 0;
}