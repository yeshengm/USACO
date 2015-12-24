/*
ID: mayeshe1
LANG: C++
PROG: preface
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
int N;
int I[5][11] = { {}, {0,1,2,3,1,0,1,2,3,1} };
int V[5][11] = { {}, {0,0,0,0,1,1,1,1,1,0} };
int X[5][11] = { {}, {0,0,0,0,0,0,0,0,0,1}, {0,1,2,3,1,0,1,2,3,1} };
int L[5][11] = { {}, {}, {0,0,0,0,1,1,1,1,1,0} };
int C[5][11] = { {}, {}, {0,0,0,0,0,0,0,0,0,1}, {0,1,2,3,1,0,1,2,3,1} };
int D[5][11] = { {}, {}, {}, {0,0,0,0,1,1,1,1,1,0} };
int M[5][11] = { {}, {}, {}, {0,0,0,0,0,0,0,0,0,1}, {0,1,2,3,1,0,1,2,3,1} };

int main()
{
	fin >> N;
	int cnt[11];
	for (int m = 0; m <11; ++m) {
		cnt[m] = 0;
	}
	for (int n = 1; n <= N; ++n) {
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j <= 9; ++j) {
				for (int k = 0; k <= 9; ++k) {
					for (int l = 0; l <= 9; ++l) {
						if (1000*i + 100*j + 10*k + l == n) {
							cnt[1] += I[1][l] + I[2][k] + I[3][j] + I[4][i];
							cnt[2] += V[1][l] + V[2][k] + V[3][j] + V[4][i];
							cnt[3] += X[1][l] + X[2][k] + X[3][j] + X[4][i];
							cnt[4] += L[1][l] + L[2][k] + L[3][j] + L[4][i];
							cnt[5] += C[1][l] + C[2][k] + C[3][j] + C[4][i];
							cnt[6] += D[1][l] + D[2][k] + D[3][j] + D[4][i];
							cnt[7] += M[3][j] + M[4][i];
						}
					}
				}
			}
		}
	}
	for (int m = 1; m <= 7; ++m) {
		if (cnt[m] != 0) {
			if (m == 1) fout << 'I';
			else if (m == 2) fout << 'V';
			else if (m == 3) fout << 'X';
			else if (m == 4) fout << 'L';
			else if (m == 5) fout << 'C';
			else if (m == 6) fout << 'D';
			else if (m == 7) fout << 'M';
			fout << ' ' << cnt[m] << endl;
		}
	}
	return 0;
}