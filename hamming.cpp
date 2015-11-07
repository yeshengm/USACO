/*
ID: mayeshe1
LANG: C++
PROG: hamming
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("hamming.in");
ofstream fout("hamming.out");

int N, B, D;
int sz = 0;
int a[100];

int hamming(int n, int m) {
	int ham = 0;
	int tmp = n ^ m;
	int bit = 1;
	while (bit <= 8) {
		if (tmp & 1 == 1)
			++ham;
		tmp = tmp >> 1;
		++bit;
	}
	return ham;
}

bool isValid(int n) {
	for (int i = sz - 1; i >= 0; --i)
		if (hamming(n, a[i]) < D)
			return false;
	return true;
}

int main() 
{
	fin >> N >> B >> D;
	for (int i = 0; i < 256 && sz != N; ++i) {
		if (isValid(i))
			a[sz++] = i;
	}
	for (int i = 0; i < sz - 1; ++i) {
		if ((i + 1) % 10 == 0)
			fout << a[i] << endl;
		else fout << a[i] << ' ';
	}
	fout << a[sz - 1] << endl;
	return 0;
}