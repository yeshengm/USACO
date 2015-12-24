/*
ID: maeyshe1
LANG: C++
PROG: sprime
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("sprime.in");
ofstream fout("sprime.out");

int dp[15][1000], sz[15], len;
int a[5] = {0, 1, 3, 7, 9};
bool isPrime(int num) {
	if (num == 1 || num == 0) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 3; i <= sqrt(num) +1; ++i)
		if (num % i == 0)
			return false;
	return true;
}
//1 3 7 9
int main()
{
	fin >> len;
	dp[1][1] = 2; dp[1][2] = 3; dp[1][3] = 5; dp[1][4] = 7;
	sz[1] = 4;
	for (int i = 2; i <= len; ++i) {
		for (int j = 1; j <= sz[i - 1]; ++j) {
			for (int k = 1; k <= 4; ++k) {
				if (isPrime(10 * dp[i - 1][j] + a[k])) {
					dp[i][++sz[i]] = 10 * dp[i - 1][j] + a[k];
				}
			}
		}
	}
	for (int i = 1; i <= sz[len]; ++i)
		fout << dp[len][i] << endl;
	return 0;
}