/*
ID: mayeshe1
LANG: C++
PROG: kimbits
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

long long a[32][32];
long long N, L, K;

void printBinary(int x, int bit) {
	if (bit == 0)
		return;
	printBinary(x / 2, bit - 1);
	fout << x % 2;
}

int main()
{
	fin >> N >> L >> K;
	for (int i = 0; i <= N; ++i)
		a[0][i] = a[i][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
		a[i][i] = a[i - 1][i - 1] * 2;
	}
	for (int i = 0; i <= N; ++i)
		for (int j = i + 1; j <= N; ++j)
		a[i][j] = a[i][i];
	long long res = 0, remain = L, num = K;
	for (int pos = N; pos >= 1; --pos) {
		res <<= 1;
		if (num > a[pos - 1][remain]) {
			num -= a[pos - 1][remain];
			res += 1;
			remain--;
		}
	}
	printBinary(res, N);
	fout << endl;
	return 0;
}