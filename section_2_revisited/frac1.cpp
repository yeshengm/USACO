/*
ID: mayeshe1
LANG: C++
PROG: frac1
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
struct number {
	int fz, fm;
} num[20000];
int N, sz = 2;

bool isPrime(int a, int b) {
	if (a == 1 || b == 1) return true;
	if (a % b == 0) return false;
	else return isPrime(b, a % b);
}
void swap(number &a, number &b) {
	number tmp = a;
	a = b; 
	b = tmp;
}
void numSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t; number mid = num[(s+t)/2];
	while (i <= j) {
		while (num[i].fz*mid.fm < num[i].fm*mid.fz) i++;
		while (num[j].fz*mid.fm > num[j].fm*mid.fz) j--;
		if (i <= j) swap(num[i++], num[j--]);
	}
	numSort(s, j);
	numSort(i, t);
}
int main()
{
	fin >> N;
	num[0].fz = 0; num[0].fm = 1;
	num[1].fz = 1; num[1].fm = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
			if (isPrime(j, i)) {
				num[sz].fz = j; num[sz].fm = i;
				sz++;
			}
		}
	}
	numSort(0, sz - 1);
	for (int i = 0; i < sz; ++i) {
		fout << num[i].fz << '/' << num[i].fm << endl;
	}
	return 0;
}