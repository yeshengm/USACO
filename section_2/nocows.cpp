/*
ID: mayeshe1
LANG: C++
PROG: nocows
*/
#include "iostream"
#include "cstdio"
#include "fstream"
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");

int N, K;
long long a[105][205]; //censhu, geshu

int main()
{
	fin >> N >> K;
	a[1][1] = 1;
	a[0][0] = 0;
	for (int i = 2; i <= K; ++i) { //censhu
		for (int j = 1; j <= N; ++j) { //geshu
			for (int x = 1; x < i - 1; ++x) { //censhu
				for (int y = 1; y < j - 1; ++y) { //geshu
					a[i][j] += 2 * a[i - 1][j - 1 - y] * a[x][y];
				}
			}
			for (int x = 1; x < j - 1; ++x) { //geshu
				a[i][j] += a[i - 1][x] * a[i - 1][j - 1 - x];
			}
			a[i][j] %= 9901;
		}
	}
	fout << a[K][N] << endl;
	return 0;
}