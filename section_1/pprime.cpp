/*
ID: mayeshe1
LANG: C++
TASK: pprime
*/
/*
可以用素数筛法做
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

int a, b;
int ib[9];

bool isPrime(int n);

int main()
{
	fin >> a >> b;
	//cout << isPrime(9) << endl;
	//while (1);
	//1 bit
	for (ib[1] = 5; ib[1] <= 9; ib[1] += 2)
		if (isPrime(ib[1]) && ib[1] >= a && ib[1] <= b)
			fout << ib[1] << endl;
	//2 bits
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		int tmp = 10 * ib[1] + ib[1];
		if (tmp > b) return 0;
		if (isPrime(tmp) && tmp >= a)
			fout << tmp << endl;
	}
	//3 bits
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			int tmp = (100 + 1) * ib[1] + 10 * ib[2];
			if (tmp > b) return 0;
			if (isPrime(tmp) && tmp >= a)
				fout << tmp << endl;
		}
	}
	//4 bits
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			int tmp = (1000 + 1) * ib[1] + (100 + 10) * ib[2];
			if (tmp > b) return 0;
			if (isPrime(tmp) && tmp >= a)
				fout << tmp << endl;
		}
	}
	//5 bit
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			for (ib[3] = 0; ib[3] <= 9; ++ib[3]) {
				int tmp = (10000 + 1) * ib[1] + (1000 + 10) * ib[2] + 100 * ib[3];
				if (tmp > b) return 0;
				if (isPrime(tmp) && tmp >= a)
					fout << tmp << endl;
			}
		}
	}
	//6 bit
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			for (ib[3] = 0; ib[3] <= 9; ++ib[3]) {
				int tmp = (100000 + 1) * ib[1] + (10000 + 10) * ib[2] + (1000 + 100) * ib[3];
				if (tmp > b) return 0;
				if (isPrime(tmp) && tmp >= a)
					fout << tmp << endl;
			}
		}
	}
	//7 bit
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			for (ib[3] = 0; ib[3] <= 9; ++ib[3]) {
				for (ib[4] = 0; ib[4] <= 9; ++ib[4]) {
					int tmp = (1000000 + 1) * ib[1] + (100000 + 10) * ib[2] + (10000 + 100) * ib[3] + 1000 * ib[4];
					if (tmp > b) return 0;
					if (isPrime(tmp) && tmp >= a)
						fout << tmp << endl;
				}
			}
		}
	}
	//8 bit
	for (ib[1] = 1; ib[1] <= 9; ib[1] += 2) {
		for (ib[2] = 0; ib[2] <= 9; ++ib[2]) {
			for (ib[3] = 0; ib[3] <= 9; ++ib[3]) {
				for (ib[4] = 0; ib[4] <= 9; ++ib[4]) {
					int tmp = (10000000 + 1) * ib[1] + (1000000 + 10) * ib[2] + (100000 + 100) * ib[3] + (10000 + 1000) * ib[4];
					if (tmp > b) return 0;
					if (isPrime(tmp) && tmp >= a)
						fout << tmp << endl;
				}
			}
		}
	}
	
	//clock_t start, end;
	//start = clock();
	//end = clock();
	//cout << (double) (start - end) / CLOCKS_PER_SEC << endl;
	return 0;
}

bool isPrime(int n) {
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}