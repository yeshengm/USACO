/*
ID: mayeshe1
PROG: barn1
LANG: C++
*/
#include "iostream"
#include "stdio.h"
#include "fstream"
using namespace std;
ifstream fin("barn1.in");
ofstream fout("barn1.out");

#define MAXBARN 200 + 10
int barn[MAXBARN] = {0};
int M, S, C;

int getWood();
int  totalWood();
void combine();

int main()
{
	fin >> M >> S >> C;
	for (int i = 0; i < C; ++i) {
		int num;
		fin >> num;
		barn[num] = 1;
	}								//init

	int nwood;						//pieces of wood
	nwood = getWood();
	while (nwood > M) {
		combine();
		--nwood;
	}
	fout << totalWood() << endl;
	return 0;
}

int getWood()
{
	int num = 0;
	bool isIn = false;
	for (int i = 1; i <= S; ++i) {
		if (barn[i] == 0) {
			isIn = false;
		} else if (!isIn) {
			++num;
			isIn = true;
		}
	}
	return num;
}

int totalWood()
{
	int cnt = 0;
	for (int i = 1; i <= S; ++i) {
		if (barn[i] == 1) {
			++cnt;
		}
	}
	return cnt;
}

void combine()
{
	int min, tval, pmin, ptval, start, end;
	bool isIn = 1;
	min = tval = S;
	pmin = ptval = 1;
	for (int i = 1; i < MAXBARN - 1; ++i) {
		if (barn[i] == 1) {
			start = i;
			break;
		} 
	}
	for (int i = MAXBARN - 1; i > 0; --i) {
		if (barn[i] == 1) {
			end = i;
			break;
		}
	}

	for (int i = start; i <= end; ++i) {
		if (barn[i] == 0) {
			if (!isIn)
				++tval;
			if (isIn) {
				tval = 1;
				ptval = i;
				isIn = 0;
			}
		} else {
			if (!isIn) {
				if (tval < min) {
					min = tval;
					pmin = ptval;
				}
				isIn = 1;
			}
		}
	}

	for (int i = 0; i < min; ++i) {
		barn[pmin+i] = 1;
	}
}