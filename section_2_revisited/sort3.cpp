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
#define min(x, y) ((x < y) ? x : y)
int N, p[1005], q[1005];
int cnt[4][4], swapCnt;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void threeSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = q[(i+j)>>1];
	while (i <= j) {
		while (q[i] < vmid) ++i;
		while (q[j] > vmid) --j;
		if (i <= j) swap(q[i++], q[j--]);
	}
	threeSort(s, j);
	threeSort(i, t);
}
int main()
{
	fin >> N;
	for (int i = 0; i < N; ++i) fin >> p[i];
	for (int i = 0; i < N; ++i) q[i] = p[i];
	threeSort(0, N - 1);
	for (int i = 0; i < N; ++i) {
		if (p[i] == 1 && q[i] == 2) ++cnt[1][2];
		else if (p[i] == 1 && q[i] == 3) ++cnt[1][3];
		else if (p[i] == 2 && q[i] == 1) ++cnt[2][1];
		else if (p[i] == 2 && q[i] == 3) ++cnt[2][3];
		else if (p[i] == 3 && q[i] == 1) ++cnt[3][1];
		else if (p[i] == 3 && q[i] == 2) ++cnt[3][2];
	}
	int tmp;
	tmp = min(cnt[1][2], cnt[2][1]); 
	swapCnt += tmp; cnt[1][2] -= tmp; cnt[2][1] -= tmp;
	tmp = min(cnt[2][3], cnt[3][2]); 
	swapCnt += tmp; cnt[2][3] -= tmp; cnt[3][2] -= tmp;
	tmp = min(cnt[3][1], cnt[1][3]); 
	swapCnt += tmp; cnt[1][3] -= tmp; cnt[3][1] -= tmp;
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			if (cnt[i][j] != 0) {
				swapCnt += 2 * cnt[i][j];
				fout << swapCnt << endl;
				return 0;
			}
		}
	}
	fout << swapCnt << endl;
	return 0;
}