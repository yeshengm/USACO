/*
ID: mayeshe1
LANG: C++
PROG: cowtour
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
using namespace std;
ifstream fin("cowtour.in");
FILE *fout = fopen("cowtour.out", "w");
const int MAXNUM = 155;
const int INFI = 200000000;
int N, x[MAXNUM], y[MAXNUM], UF[MAXNUM];
bool adj[MAXNUM][MAXNUM];
double dist[MAXNUM][MAXNUM];
double minD = INFI;
void init();
int UFFind(int i);
void UFUnion(int a, int b);
void floyd();

inline int max(int a, int b) { return (a > b) ? a : b; }

int main()
{
	init();
	floyd();
	for (int i = 1; i <= N; ++i) {
		double tmpMax = 0;
		for (int j = 1; j <= N; ++j) {
			if (i != j && UFFind(i) == UFFind(j)) {
				tmpMax = (dist[i][j] > tmpMax) ? dist[i][j] : tmpMax;
			}
		}
		dist[0][i] = tmpMax;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i != j && UFFind(i) != UFFind(j)) {
				double D1 = dist[0][i], D2 = dist[0][j];
				double tmp = D1 + D2 + sqrt(((double)(x[i] - x[j]))*((double)(x[i] - x[j])) 
							+ ((double)(y[i] - y[j]))*((double)(y[i] - y[j])));
				double maxD1 = 0, maxD2 = 0;
				for (int k = 1; k <= N; ++k) {
					if (UFFind(k) == UFFind(i)) {
						maxD1 = (dist[0][k] > maxD1) ? dist[0][k] : maxD1;
					} else if (UFFind(k) == UFFind(j)) {
						maxD2 = (dist[0][k] > maxD2) ? dist[0][k] : maxD2;
					}
				}
				double tmpMax = max(maxD1, max(maxD2, tmp));
				minD = (tmpMax < minD) ? tmpMax : minD;
			}
		}
	}
	fprintf(fout, "%.6lf\n", minD);
	return 0;
}

void init() {
	fin >> N;
	for (int i = 1; i <= N; ++i)
		fin >> x[i] >> y[i];
	fin.get();
	for (int i = 0; i <= N; ++i)
		UF[i] = -1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			char ch = fin.get();
			adj[i][j] = (bool) (ch - '0');
			if (adj[i][j]) UFUnion(UFFind(i), UFFind(j));
		}
		fin.get();
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (adj[i][j]) {
				dist[i][j] = sqrt(((double)(x[i] - x[j]))*((double)(x[i] - x[j])) 
							+ ((double)(y[i] - y[j]))*((double)(y[i] - y[j])));
			} else if (i != j && !adj[i][j]) {
				dist[i][j] = INFI;
			}
		}
	}
}
int UFFind(int i) {
	if (UF[i] < 0) return i;
	else return UF[i] = UFFind(UF[i]);
}
void UFUnion(int a, int b) {
	a = UFFind(a); b = UFFind(b);
	if (a == b) return;
	if (a < b) { UF[a] += UF[b]; UF[b] = a; }
	else { UF[b] += UF[a]; UF[a] = b; }
}
void floyd() {
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			if (i != k) {
				for (int j = 1; j <= N; ++j) {
					if (i != j && j != k && dist[i][k] < INFI && dist[k][j] < INFI
						&& dist[i][k] + dist[k][j] < dist[i][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}
	}
}