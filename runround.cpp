/*
ID: mayeshe1
LANG: C++
PROG: runround
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

long long M;
int a[100];
int currBit;

int getBit(long long n) {
	int i = 0;
	while (n != 0) {
		n /= 10;
		++i;
	}
	return i;
}

void convert(long long n) {
	int ibit = getBit(n);
	for (int i = 0; i < ibit; ++i) {
		a[i] = n % 10;
		n /= 10;
	}
	for (int i = 0; i <= (ibit - 1) / 2; ++i) {
		int tmp = a[i];
		a[i] = a[ibit - 1 - i];
		a[ibit -1 - i] = tmp;
	}
}

bool isRepeat() {
	for (int i = 0; i < currBit; ++i) {
		for (int j = i + 1; j < currBit; ++j)
			if (a[i] == a[j])
				return true;
	}
	return false;
}

bool existZero() {
	for (int i = 0; i < currBit; ++i) {
		if (a[i] == 0)
			return true;
	}
	return false;
}

bool isCycle() {
	int mark[20];
	memset(mark, 0, 80);
	int pos = 0;
	for (int i = 0; i < currBit; ++i) {
		pos += a[pos];
		pos = pos % currBit;
		mark[pos] = 1;
	}
	for (int i = 0; i < currBit; ++i)
		if (mark[i] != 1)
			return false;
	return true;
}

int main() 
{
	fin >> M;
	while (++M) {
		currBit = getBit(M);
		convert(M);
		if (!existZero() && !isRepeat() && isCycle()) {
			fout << M << endl;
			break;
		}
	}
	return 0;
}