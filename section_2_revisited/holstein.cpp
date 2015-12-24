/*
ID:maeyshe1
LANG: C++
PROG: holstein
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
int NV, V[30]; //vitamin MAX 25
int NG, G[20][30]; //siliao MAX 15
void init() {
	fin >> NV;
	for (int i = 1; i <= NV; ++i)
		fin >> V[i];
	fin >> NG;
	for (int i = 1; i <= NG; ++i)
		for (int j = 1; j <= NV; ++j)
			fin >> G[i][j];
}
bool mark[20]; 
bool minMark[20]; int minlen = 0x7fffffff;

void check(int dep) {
	int currlen = 0;
	for (int i = dep; i >= 1; --i)
		if (mark[i]) ++currlen;
	if (currlen > minlen) return;
	int tmp[30];
	for (int i = 1; i <= NV; ++i) tmp[i] = 0;
	for (int i = 1; i <= dep; ++i) {
		if (mark[i]) {
			for (int j = 1; j <= NV; ++j) {
				tmp[j] += G[i][j];
			}
		}
	}
	for (int i = 1; i <= NV; ++i)
		if (tmp[i] < V[i])
			return;
	if (currlen == minlen) {
		for (int i = 1; i <= currlen; ++i) {
			if (!mark[i] && minMark[i])
				return;
			else if (mark[i] && !minMark[i])
				break;
		}
	}
	minlen = currlen;
	for (int i = 1; i <= dep; ++i)
		minMark[i] = mark[i];
	for (int i = dep+1; i <= NG; ++i)
		minMark[i] = false;
}

void dfs(int dep) {
	check(dep);
	if (dep == NG + 1) return;
	mark[dep] = false;
	dfs(dep+1);
	mark[dep] = true;
	dfs(dep+1);
}

int main()
{
	init();
	dfs(1);
	fout << minlen << ' ';
	int i;
	for (i = 1; i <= NG; ++i)
		if (minMark[i]) {
			fout << i;
			break;
		}
	for (i++; i <= NG; ++i)
		if (minMark[i])
			fout << ' ' << i;
	fout << endl;
	return 0;
}