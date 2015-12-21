#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("numtri.in");
ofstream fout("numtri.out");

int N, res[1001][1001], val[1001][1001];

inline int intmax(int a, int b) { return (a > b) ? a : b; }

int main() {
	fin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j)
			fin >> val[i][j];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i == 1 && j == 1) { res[i][j] = val[i][j]; continue; }
			if (j == 1) { res[i][j] = res[i - 1][j] + val[i][j]; continue; }
			if (j == i) { res[i][j] = res[i - 1][j - 1]; continue; }
			res[i][j] = intmax(res[i - 1][j], res[i - 1][j - 1]) + val[i][j];
		}
	}
	int max = -1;
	for (int i = 1; i <= N; ++i)
		max = (res[N][i] > max) ? res[N][i] : max;
	cout << max << endl;
	return 0;
}