/*
ID: mayeshe1
PROG: skidesign
LANG: C++
*/
#include "iostream"
#include "fstream"
#include "cstdio"
#include "cstdlib"
using namespace std;
ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

#define MAN_N 1000 + 10

int hill[MAN_N];
int N;

int cmp(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int calCost(int maxh)
{
	int cost = 0;
	for (int i = 1; i <= N; ++i) {
		if (hill[i] < maxh-17)
			cost += (maxh - 17 - hill[i]) * (maxh - 17 - hill[i]);
		else if (hill[i] > maxh) {
			cost += (hill[i] - maxh) * (hill[i] - maxh);
		}
	}
	return cost;
}

int minCost()
{
	int maxh;
	int mincost = calCost(hill[N]);
	for (maxh = hill[1] + 17; maxh <= hill[N]; maxh++) {
		if (calCost(maxh) <= mincost)
			mincost = calCost(maxh);
	}
	return mincost;
}

int main()
{
	fin >> N;
	for (int i = 1; i <= N; ++i)
		fin >> hill[i];
	qsort(hill + 1, N, sizeof(int), cmp);
	if (hill[N]-hill[1] <= 17)
		fout << 0 << endl;
	else
		fout << minCost() << endl;
	return 0;
}