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

int N;
int halfSum;
long long dp[40][800];

int main() 
{
	fin >> N;
	dp[1][1] = 1;
	halfSum = (N*(N + 1)/2.0)/2.0;
	if ((N * (N + 1)) % 4 != 0) {
		fout << '0' << endl;
		return 0;
	}
	for (int i = 2; i <= 39; ++i) {
		for (int j = 1; j <= i*(i + 1) / 2; ++j)
			dp[i][j] += dp[i - 1][j] + dp[i - 1][j-i];
	}
	fout << dp[N][halfSum] << endl;
	return 0;
}