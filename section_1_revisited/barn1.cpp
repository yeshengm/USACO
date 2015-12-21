/*
ID: mayeshe1
LANG: C++
PROG: barn1
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");

int M, S, C;
bool barn[201];
int blank[201], size = 0;

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void quickSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = blank[(s + t) >> 1];
	while (i <= j) {
		while (blank[i] < vmid) ++i;
		while (blank[j] > vmid) --j;
		if (i <= j) swap(blank[i++], blank[j--]);
	}
	quickSort(s, j);
	quickSort(i, t);
}

int main()
{
	fin >> M >> S >> C;
	int pos;
	for (int i = 1; i <= C; ++i) { fin >> pos; barn[pos] = true; }
	int head, tail;
	for (head = 1; head <= S; ++head)
		if (barn[head]) break;
	for (tail = S; tail >= 1; --tail)
		if (barn[tail]) break;
	bool barnEmpty = true;
	int milkBarnNum = 0;
	for (int i = head; i <= tail; ++i) {
		if (barn[i]) {
			if (barnEmpty) { barnEmpty = false; milkBarnNum++; }
		} else if (!barn[i]) {
			if (barnEmpty) { ++blank[size]; }
			else if (!barnEmpty) { barnEmpty = true; size++; blank[size]++; }
		}
	}
	if (milkBarnNum <= M) fout << C << endl;
	else {
		quickSort(1, size);
		int sum = C;
		for (int i = 1; i <= milkBarnNum - M; ++i)
			sum += blank[i];
		fout << sum << endl;
	}
	return 0;
}