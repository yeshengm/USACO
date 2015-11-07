/*
ID: mayeshe1
LANG: C++
PROG: holstein
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");

int V;
int minV[30];
int G;
int scoop[20][30];
int minG = 200000000;
int minPath[20];
int currPath[20];
int currV[30];

void dfs(int depth, int cnt) {
	if (depth == G + 1) {
		for (int i = 1; i <= V; ++i)
			if (currV[i] < minV[i])
				return;
		if (cnt < minG) {
			minG = cnt;
			for (int i = 1; i <= G; ++i)
				minPath[i] = currPath[i];
		}
		return;
	}
	for (int i = 1; i <= V; ++i)
		currV[i] += scoop[depth][i];
	currPath[depth] = 1;
	dfs(depth + 1, cnt + 1);
	for (int i = 1; i <= V; ++i)
		currV[i] -= scoop[depth][i];
	currPath[depth] = 0;
	dfs(depth + 1, cnt);
}
int main() 
{
	fin >> V;
	for (int i = 1; i <= V; ++i) fin >> minV[i];
	fin >> G;
	for (int i = 1; i <= G; ++i)
		for (int j = 1; j <= V; ++j)
			fin >> scoop[i][j];
	dfs(1, 0);
	fout << minG << ' ';
	int tail = G;
	while (minPath[tail] == 0) --tail;
	for (int i = 1; i < tail; ++i)
		if (minPath[i] == 1)
			fout << i << ' ';
	fout << tail << endl;
	return 0;
}