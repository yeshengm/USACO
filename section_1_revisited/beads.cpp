/*
ID: mayeshe1
LANG: C++
PROG: beads
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("beads.in");
ofstream fout("beads.out");

const char R = 'r';
const char B = 'b';
const char W = 'w';

int N, maxNum;
char currLeft, currRight;
char input[1000];
char necklace[10000];

int getNum(int p) {
	int cntLeft = 0, cntRight = 0;
	currLeft = currRight = '\0';
	for (int i = p; i >= 1; --i) {
		if (currLeft == 0) {
			if (necklace[i] != W)
				currLeft = necklace[i];
		} else if (currLeft != 0) {
			if (necklace[i] != W && currLeft != necklace[i]) break;
		}
		++cntLeft;
	}
	for (int i = p + 1; i <= 3 * N; ++i) {
		if (currRight == 0) {
			if (necklace[i] != W)
				currRight = necklace[i];
		} else if (currRight != 0) {
			if (necklace[i] != W && necklace[i] != currRight) break;
		}
		++cntRight;
	}
	return cntLeft + cntRight;
}

int main()
{
	fin >> N; fin.get();
	for (int i = 1; i <= N; ++i) fin.get(input[i]);
	for (int i = 1; i <= N; ++i) {
		necklace[i] = necklace[i + N] = necklace[i + 2 * N] = input[i];
	}
	for (int i = N; i <= 2 * N; ++i)
		maxNum = (getNum(i) > maxNum) ? getNum(i) : maxNum;
	if (maxNum > N) fout << N;
	else fout << maxNum;
	fout << endl;
	return 0;
}