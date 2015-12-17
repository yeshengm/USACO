/*
ID: mayeshe1
LANG: C++
PROG: sort3
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sort3.in");
ofstream fout("sort3.out");

int a[1005];
int sa[1005];
int cnt[7];
int N;
int istep = 0;

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}
void qsort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vm = sa[(s + t) >> 1];
	while (i <= j) {
		while (sa[i] < vm) ++i;
		while (sa[j] > vm) --j;
		if (i <= j) swap(sa[i++], sa[j--]);
	}
	qsort(s, j);
	qsort(i, t);
}
void clacCnt(int i, int j) {
	if (cnt[i] > cnt[j]) {
		istep += cnt[j];
		cnt[i] -= cnt[j];
		cnt[j] = 0;
	} else {
		istep += cnt[i];
		cnt[j] -= cnt[i];
		cnt[i] = 0;
	}
}

int main() 
{
	fin >> N;
	for (int i = 0; i < N; ++i) fin >> a[i];
	for (int i = 0; i < N; ++i) sa[i] = a[i];
	qsort(0, N - 1);
	for (int i = 0; i < N; ++i) {
		if (a[i] == 1 && sa[i] == 2) ++cnt[1];
		if (a[i] == 2 && sa[i] == 1) ++cnt[2];
		if (a[i] == 1 && sa[i] == 3) ++cnt[3];
		if (a[i] == 3 && sa[i] == 1) ++cnt[4];
		if (a[i] == 2 && sa[i] == 3) ++cnt[5];
		if (a[i] == 3 && sa[i] == 2) ++cnt[6];
	}
	clacCnt(1, 2);
	clacCnt(3, 4);
	clacCnt(5, 6);
	for (int i = 1; i <= 6; ++i) {
		if (cnt[i] != 0) {
			istep += 2 * cnt[i];
			break;
		}
	}
	fout << istep << endl;
	return 0;
}