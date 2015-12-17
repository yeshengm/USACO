/*
ID: mayeshe1
LANG: C++
TASK: frac1
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");

struct frac {
	int fz;
	int fm;
};

bool fraccmp(frac f1, frac f2) {
	return f1.fz * f2.fm < f1.fm * f2.fz;
}
bool isPrime(int i, int j) {
	if (i % j == 0 && j == 1) return true;
	if (i % j == 0 && j != 1) return false;
	isPrime(j, i % j);
}

int N;
frac st[30000];
int sz = 0;

int main()
{
	fin >> N;
	for (int i = 2; i <= N; ++i) //fenmu
		for (int j = 1; j < i; ++j) //fenzi
			if (isPrime(i, j)) {
				st[sz].fz = j;
				st[sz].fm = i;
				sz++;
			}
	st[sz].fz = 0; st[sz].fm = 1; sz++;
	st[sz].fz = 1; st[sz].fm = 1; sz++;
	sort(st, st + sz, fraccmp);
	for (int i = 0; i < sz; ++i)
		fout << st[i].fz << '/' << st[i].fm << endl;
	return 0;
}