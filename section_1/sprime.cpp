/*
ID: mayeshe1
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

int N;
//int prime[1000000] = { -1, -1, 1 };

bool isPrime(int n);
bool isSprime(int n);

int main()
{
	std::ios::sync_with_stdio(false);
	/*clock_t s, e;
	s = clock();*/
	fin >> N;
	int beg = (int) pow(10, N - 1);
	int end = (int) pow(10, N) - 1;
	if (N == 1) {
		fout << '2' << endl << '3' << endl << '5' << endl << '7' << endl;
		return 0;
	}
	if (N <= 7) {
		for (int i = beg + 1; i <= end; i += 2) {
			bool flag = true;
			int tmp;
			for (int divpow = N - 1; divpow >= 0; divpow--) {
				int div = (int)pow(10, divpow);
				tmp = i / div;
				if (isPrime(tmp) == false) {
					flag = false;
					break;
				}
			}
			if (flag == true)
				fout << i << endl;
		}
		return 0;
	}
	if (N == 8) {
		int bit[10];
		for (bit[1] = 2; bit[1] == 2 || bit[1] == 3 || bit[1] == 5 || bit[1] == 7;) {
			for (bit[2] = 1; bit[2] <= 9; bit[2] += 2)
				for (bit[3] = 1; bit[3] <= 9; bit[3] += 2)
					for (bit[4] = 1; bit[4] <= 9; bit[4] += 2)
						for (bit[5] = 1; bit[5] <= 9; bit[5] += 2)
							for (bit[6] = 1; bit[6] <= 9; bit[6] += 2)
								for (bit[7] = 1; bit[7] <= 9; bit[7] += 2)
									for (bit[8] = 1; bit[8] <= 9; bit[8] += 2) {
										//int tmp = 10000000 * bit[1] + 1000000 * bit[2] + 100000 * bit[3] +
											//10000 * bit[4] + 1000 * bit[5] + 100 * bit[6] + 10 * bit[7] + bit[8];
										int tmp = 0;
										bool flag = true;
										for (int i = 1; i <= 8; ++i) {
											tmp = 10 * tmp + bit[i];
											if (!isPrime(tmp)) {
												flag = false;
												break;
											}
										}
										if (flag == true)
											fout << tmp << endl;
									}
			if (bit[1] == 2) bit[1] = 3;
			else if (bit[1] == 3) bit[1] = 5;
			else if (bit[1] == 5) bit[1] = 7;
			else break;
		}
	}
	/*e = clock();
	cout << (double)(e - s) / CLOCKS_PER_SEC;
	while (1);*/
	return 0;
}

bool isPrime(int n) {
	if (n == 1 || n == 0) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

//bool isSprime(int num) {
//	for (int i = N - 1; i >= 0; --i) {
//		int div = (int) pow(10, i);
//		int tmp = num / div;
//		if (prime[tmp] == -1)
//			return false;
//	}
//	return true;
//}