/*
ID: mayeshe1
LANG: C++
PROG: skidesign
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("skidesign.in");
ofstream fout("skidesign.out");
#define INF 0x7fffffff
#define sqr(x) ((x)*(x))
int N, h[1001];
int minh = INF, maxh, minCost = INF;

int main()
{
	fin >> N;
	for (int i = 0; i < N; ++i) {
		fin >> h[i];
		minh = (h[i] < minh) ? h[i] : minh;
		maxh = (h[i] > maxh) ? h[i] : maxh;
	}
	if (maxh - minh <= 17) { fout << 0 << endl; return 0; }
	for (int tmp = minh; tmp + 17 <= maxh; ++tmp) {
		int tmpCost = 0;
		for (int i = 0; i < N; ++i) {
			if (h[i] < tmp) tmpCost += sqr(h[i] - tmp);
			else if (h[i] > tmp + 17) tmpCost += sqr(h[i] - tmp - 17);
		}
		minCost = (tmpCost < minCost) ? tmpCost : minCost;
	}
	fout << minCost << endl;
	return 0;
}