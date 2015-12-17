/*
ID: mayeshe1
LANG: C++
PROG: dualpal
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

int N, S;

bool Pal(int num, int B) {
	int bit = 0, trans[100];
	while (num != 0) {
		trans[++bit] = num % B;
		num /= B;
	}
	for (int i = 1; i <= (bit + 1) / 2; ++i)
		if (trans[i] != trans[bit - i + 1])
			return false;
	return true;
}

bool dualPal(int num) {
	int palCnt = 0;
	for (int i = 2; i <= 10 && palCnt < 2; ++i) {
		if (Pal(num, i))
			++palCnt;
	}
	if (palCnt >= 2) return true;
	else return false;
}

int main()
{
	fin >> N >> S;
	int tmpNum = S + 1;
	while (1) {
		if (dualPal(tmpNum)) { fout << tmpNum << endl; --N; }
		++tmpNum;
		if (N == 0) break;
	}
	return 0;
}