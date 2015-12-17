/*
ID: mayeshe1
LANG: C++
PROG: castle
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("castle.in");
ofstream fout("castle.out");

int wallnum;
bool north[60][60];
bool south[60][60];
bool west[60][60];
bool east[60][60];
int type[60][60];
int M, N;
int typenum;
int sz[3600];
int iMTR;
int rowMTR;
int colMTR;
int posMTR;


void setWall(int row, int col, int num) {
	if (num >= 8) { south[row][col] = 1; num -= 8; }
	if (num >= 4) { east[row][col] = 1; num -= 4; }
	if (num >= 2) { north[row][col] = 1; num -= 2; }
	if (num >= 1) { west[row][col] = 1; num -= 1; }
}
void getRoomType(int row, int col) {
	if (row < 1 || row > N || col < 1 || col > M)
		return;
	if (type[row][col] == 0)
		type[row][col] = ++typenum;
	if (!north[row][col] && row > 1 && type[row - 1][col] == 0) {
		if (type[row - 1][col] == 0) {
		type[row - 1][col] = type[row][col];
		getRoomType(row - 1, col);
		}
	}
	if (!south[row][col] && row < N &&type[row + 1][col] == 0) {
		if (type[row + 1][col] == 0) {
			type[row + 1][col] = type[row][col];
			getRoomType(row + 1, col);
		}
	}
	if (!west[row][col] && col > 1 &&type[row][col - 1] == 0) {
		if (type[row][col - 1] == 0) {
			type[row][col - 1] = type[row][col];
			getRoomType(row, col - 1);
		}
	}
	if (!east[row][col] && col < M && type[row][col + 1] == 0) {
		if (type[row][col + 1] == 0) {
			type[row][col + 1] = type[row][col];
			getRoomType(row, col + 1);
		}
	}
}

int main() 
{
	fin >> M >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			fin >> wallnum;
			setWall(i, j, wallnum);
		}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
				getRoomType(i, j);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			++sz[type[i][j]];
	int maxsz = 0;
	for (int i = 1; i <= typenum; ++i)
		maxsz = (maxsz < sz[i]) ? sz[i] : maxsz;
	for (int j = 1; j <= M; ++j)
		for (int i = N; i >= 2; --i)
			if (north[i][j] == 1) {
				int tmp;
				if (type[i - 1][j] == type[i][j])
					tmp = sz[type[i][j]];
				else if (type[i - 1][j] != type[i][j])
					tmp = sz[type[i][j]] + sz[type[i - 1][j]];

				if (tmp > iMTR) {
					iMTR = tmp;
					rowMTR = i;
					colMTR = j;
					posMTR = 1;
				}
			}
	for (int j = 1; j <= M - 1; ++j)
		for (int i = N; i >= 1; --i)
			if (south[i][j] == 1) {
				int tmp;
				if (type[i][j + 1] == type[i][j])
					tmp = sz[type[i][j]];
				else if (type[i][j + 1] != type[i][j])
					tmp = sz[type[i][j]] + sz[type[i][j + 1]];

				if (tmp > iMTR) {
					iMTR = tmp;
					rowMTR = i;
					colMTR = j;
					posMTR = 2;
				} else if (tmp == iMTR) {
					if (j < colMTR || (j == colMTR && i > rowMTR)) {
						iMTR = tmp;
						rowMTR = i;
						colMTR = j;
						posMTR = 2;
					}
				}
			}
	fout << typenum << endl;
	fout << maxsz << endl;
	fout << iMTR << endl;
	fout << rowMTR << ' ' << colMTR << ' ';
	if (posMTR == 1) fout << 'N';
	else fout << 'E';
	fout << endl;
	return 0;
}