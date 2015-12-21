/*
ID: mayeshe1
LANG: C++
PROG: comehome
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");

int const INF = 200000000;
int const MAXNUM = 150;
int P, dist[MAXNUM][MAXNUM];
bool adj[MAXNUM][MAXNUM];

void init() {
	fin >> P;
	for (int i = 1; i < MAXNUM; ++i)
		for (int j = 1; j < MAXNUM; ++j)
			dist[i][j] = INF;
	char s, t;
	int w;
	for (int i = 1; i <= P; ++i) {
		fin >> s >> t >> w;
		adj[s][t] = true;
		dist[s][t] = (w < dist[s][t]) ? w : dist[s][t];
		dist[t][s] = dist[s][t];
	}
}

void floyd() {
	for (int k = 1; k < MAXNUM; ++k) {
		for (int i = 1; i < MAXNUM; ++i) {
			if (k != i) {
				for (int j = 1; j < MAXNUM; ++j) {
					if (j != i && j != k && dist[i][k] < INF && dist[k][j] < INF) {
						int currDist = dist[i][k] + dist[k][j];
						dist[i][j] = (currDist < dist[i][j]) ? currDist : dist[i][j];
					}
				}
			}
		}
	}
}

int main()
{
	init();
	floyd();
	int minlen = INF, pos = 0;
	for (int i = 'A'; i < 'Z'; ++i) {
		if (dist['Z'][i] < minlen) {
			minlen = dist['Z'][i];
			pos = i;
		}
	}
	fout << (char) pos << ' ' << minlen << endl;
	return 0;
}