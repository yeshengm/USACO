/*
ID: mayeshe1
LANG: C++
PROG: maze1
*/
#include "iostream"
#include "fstream"
#include "queue"
using std::ifstream;
using std::ofstream;
using std::queue;
using std::cout;
using std::endl;
ifstream fin("maze1.in");
ofstream fout("maze1.out");

int H, W;
int step1[110][50];
int step2[110][50];
bool u[110][50], d[110][50], l[110][50], r[110][50];
int sx1, sy1, sx2, sy2;
int scnt = 0;
int maxPath;
queue<int> Q1x, Q1y, Q2x, Q2y;
//int Q1cnt, Q2cnt;

void init() {
	for (int i = 0; i < 105; ++i) {
		for (int j = 0; j < 45; ++j)
			step1[i][j] = step2[i][j] = 200000000;
	}
	fin >> W >> H;
	char ch;
	ch = fin.get();
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			ch = fin.get();
			ch = fin.get();
			if (ch == '-') {
				d[i - 1][j] = u[i][j] = false;
			} else if (ch == ' ') {
				d[i - 1][j] = u[i][j] = true;
			}
		}
		fin.get(); fin.get();
		for (int j = 1; j <= W; ++j) {
			ch = fin.get();
			if (ch == '|') {
				r[i][j - 1] = l[i][j] = false;
			} else if (ch == ' ') {
				r[i][j - 1] = l[i][j] = true;
			}
			fin.get();
		}
		ch = fin.get();
		if (ch == '|') {
			r[i][W] = l[i][W + 1] = false;
		} else if (ch == ' ') {
			r[i][W] = l[i][W + 1] = true;
		}
		fin.get();
	}
	for (int j = 1; j <= W; ++j) {
		ch = fin.get(); ch = fin.get();
		if (ch == '-') {
			d[H][j] = u[H + 1][j] = false;
		} else if (ch == ' ') {
			d[H][j] = u[H + 1][j] = true;
		}
	}
}

void findSource() {
	for (int i = 1; i <= W; ++i) {
		if (d[0][i] == true && scnt == 0) { sx1 = 0; sy1 = i; scnt++; } 
		else if (d[0][i] == true && scnt == 1) { sx2 = 0; sy2 = i; scnt++; }
	}
	for (int i = 1; i <= W; ++i) {
		if (u[H + 1][i] == true && scnt == 0) { sx1 = H + 1; sy1 = i; scnt++; } 
		else if (u[H + 1][i] == true && scnt == 1) { sx2 = H + 1; sy2 = i; scnt++; }
	}
	for (int i = 1; i <= H; ++i) {
		if (r[i][0] == true && scnt == 0) { sx1 = i; sy1 = 0; scnt++; } 
		else if (r[i][0] == true && scnt == 1) { sx2 = i; sy2 = 0; scnt++; }
	}
	for (int i = 1; i <= H; ++i) {
		if (l[i][W + 1] == true && scnt == 0) { sx1 = i; sy1 = W + 1; scnt++; } 
		else if (l[i][W + 1] == true && scnt == 1) { sx2 = i; sy2 = W + 1; scnt++; }
	}
}

void bfs1() {
	Q1x.push(sx1); Q1y.push(sy1);
	while (!Q1x.empty()) {
		int tmpx = Q1x.front(), tmpy = Q1y.front();
		Q1x.pop(); Q1y.pop();
		if (u[tmpx][tmpy] && step1[tmpx][tmpy] + 1 < step1[tmpx - 1][tmpy]) {
			step1[tmpx - 1][tmpy] = step1[tmpx][tmpy] + 1;
			Q1x.push(tmpx - 1); Q1y.push(tmpy);
		}
		if (d[tmpx][tmpy] && step1[tmpx][tmpy] + 1 < step1[tmpx + 1][tmpy]) {
			step1[tmpx + 1][tmpy] = step1[tmpx][tmpy] + 1;
			Q1x.push(tmpx + 1); Q1y.push(tmpy);
		}
		if (l[tmpx][tmpy] && step1[tmpx][tmpy] + 1 < step1[tmpx][tmpy - 1]) {
			step1[tmpx][tmpy - 1] = step1[tmpx][tmpy] + 1;
			Q1x.push(tmpx); Q1y.push(tmpy - 1);
		}
		if (r[tmpx][tmpy] && step1[tmpx][tmpy] + 1 < step1[tmpx][tmpy + 1]) {
			step1[tmpx][tmpy + 1] = step1[tmpx][tmpy] + 1;
			Q1x.push(tmpx); Q1y.push(tmpy + 1);
		}
	}
}

void bfs2() {
	Q2x.push(sx2); Q2y.push(sy2);
	while (!Q2x.empty()) {
		int tmpx = Q2x.front(), tmpy = Q2y.front();
		Q2x.pop(); Q2y.pop();
		if (u[tmpx][tmpy] && step2[tmpx][tmpy] + 1 < step2[tmpx - 1][tmpy]) {
			step2[tmpx - 1][tmpy] = step2[tmpx][tmpy] + 1;
			Q2x.push(tmpx - 1); Q2y.push(tmpy);
		}
		if (d[tmpx][tmpy] && step2[tmpx][tmpy] + 1 < step2[tmpx + 1][tmpy]) {
			step2[tmpx + 1][tmpy] = step2[tmpx][tmpy] + 1;
			Q2x.push(tmpx + 1); Q2y.push(tmpy);
		}
		if (l[tmpx][tmpy] && step2[tmpx][tmpy] + 1 < step2[tmpx][tmpy - 1]) {
			step2[tmpx][tmpy - 1] = step2[tmpx][tmpy] + 1;
			Q2x.push(tmpx); Q2y.push(tmpy - 1);
		}
		if (r[tmpx][tmpy] && step2[tmpx][tmpy] + 1 < step2[tmpx][tmpy + 1]) {
			step2[tmpx][tmpy + 1] = step2[tmpx][tmpy] + 1;
			Q2x.push(tmpx); Q2y.push(tmpy + 1);
		}
	}
}


int main() {
	init();
	findSource();
	step1[sx1][sy1] = step2[sx2][sy2] = 0;
	bfs1(); bfs2();
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			int tmpMin = (step1[i][j] < step2[i][j]) ? step1[i][j] : step2[i][j];
			maxPath = (tmpMin > maxPath) ? tmpMin : maxPath;
		}
	}
	fout << maxPath << endl;
	return 0;
}