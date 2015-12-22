/*
ID: mayeshe1
LANG: C++
PROG: agrinet
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");

const int MAXNUM = 105;

struct edge {
	int s, t, w;
} e[MAXNUM * (MAXNUM + 1) / 2 + 5];
int N;
int dist[MAXNUM][MAXNUM], UF[MAXNUM], cost;
int UFfind(int x) {
	if (UF[x] < 0) return x;
	return UF[x] = UFfind(UF[x]);
}
void UFunion(int x, int y) {
	x = UFfind(x); y = UFfind(y);
	if (x == y) return;
	if (UF[x] < UF[y]) { UF[x] += UF[y]; UF[y] = x; }
	else { UF[y] += UF[x]; UF[x] = y; }
}
void swap(edge &x, edge &y) {
	edge tmp = x;
	x = y; 
	y = tmp;
}
void edgeSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = e[(s + t) >> 1].w;
	while (i <= j) {
		while (e[i].w < vmid) ++i;
		while (e[j].w > vmid) --j;
		if (i <= j) swap(e[i++], e[j--]);
	}
	edgeSort(s, j);
	edgeSort(i, t);
}

int main()
{
	fin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			fin >> dist[i][j];
	int pos = 0;
	for (int i = 1; i <= N; ++i) UF[i] = -1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < i; ++j) {
				++pos;
				e[pos].s = i;
				e[pos].t = j;
				e[pos].w = dist[i][j];
		}
	}
	edgeSort(1, pos);
	for (int i = 1; i <= pos; ++i) {
		int from = UFfind(e[i].s), to = UFfind(e[i].t);
		if (from != to) { 
			UFunion(from, to);
			cost += e[i].w;
		}
	}
	fout << cost << endl;
	return 0;
}