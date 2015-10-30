/*
ID: mayeshe1
LANG: C++
TASK: numtri
*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <cmath>
using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int N;
int im = 0;
int mat[1000 + 5][1000 + 5];

int main()
{
	std::ios::sync_with_stdio(false);
	fin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			fin >> mat[i][j]; 
		}
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			mat[i][j] += (mat[i - 1][j] > mat[i - 1][j - 1]) ? mat[i - 1][j] : mat[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; ++i) {
		im = (mat[N][i] > im) ? mat[N][i] : im;
	}
	fout << im << endl;
	return 0;
}