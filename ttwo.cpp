/*
ID: mayeshe1
LANG: C++
PROG: ttwo
*/
#include "iostream"
#include "cstdio"
#include "fstream"
#include "cstring"
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

const int E = 1;
const int S = 2;
const int W = 3;
const int N = 4;

int maze[12][12];
int initRowF, initColF, initRowC, initColC;
int rowF, colF, rowC, colC;
int initDirF, initDirC;
int dirF, dirC;
int cnt = 0;

void init() {
	dirF = dirC = initDirC = initDirF = N;
	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 12; ++j)
			maze[i][j] = -1;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			char ch;
			while ((ch = fin.get()) == '\n') ;
			if (ch == '.') maze[i][j] = 0;
			else if (ch == 'C') {
				maze[i][j] = 0;
				initRowC = rowC = i;
				initColC = colC = j;
			} else if (ch == 'F') {
				maze[i][j] = 0;
				initRowF = rowF = i;
				initColF = colF = j; 
			}
		}
	}
}

void step() {
	if (dirF == N) {
		if (maze[rowF - 1][colF] == 0) { rowF--; }
		else if (maze[rowF - 1][colF] == -1) { dirF = E; }
	} else if (dirF == E) {
		if (maze[rowF][colF + 1] == 0) { colF++; }
		else if (maze[rowF][colF + 1] == -1) { dirF = S; }
	} else if (dirF == S) {
		if (maze[rowF + 1][colF] == 0) { rowF++; }
		else if (maze[rowF + 1][colF] == -1) { dirF = W; }
	} else if (dirF == W) {
		if (maze[rowF][colF - 1] == 0) { colF--; }
		else if (maze[rowF][colF - 1] == -1) { dirF = N; }
	}
	if (dirC == N) {
		if (maze[rowC - 1][colC] == 0) { rowC--; }
		else if (maze[rowC - 1][colC] == -1) { dirC = E; }
	} else if (dirC == E) {
		if (maze[rowC][colC + 1] == 0) { colC++; }
		else if (maze[rowC][colC + 1] == -1) { dirC = S; }
	} else if (dirC == S) {
		if (maze[rowC + 1][colC] == 0) { rowC++; }
		else if (maze[rowC + 1][colC] == -1) { dirC = W; }
	} else if (dirC == W) {
		if (maze[rowC][colC - 1] == 0) { colC--; }
		else if (maze[rowC][colC - 1] == -1) { dirC = N; }
	}
}

bool judge() {
	if (rowC == rowF && colC == colF) {
		fout << cnt << endl;
		return true;
	} else if (rowC == initRowC && colC == initColC &&
		dirC == initDirC && dirF == initDirF) {
		fout << '0' << endl;
		return true;
	}
	return false;
}

int main()
{
	init();
	while (1) {
		step();
		cnt++;
		if (judge())
			break;
		if (cnt == 100) {
			initRowC = rowC;
			initColC = colC;
			initDirC = dirC;
			initDirF = dirF;
		}
	}
	return 0;
}