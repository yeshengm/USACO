/*
ID: mayeshe1
LANG: C++
PROG: money
*/
#include "iostream"
#include "fstream"
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");

int V, N;
int a[30];
long long cnt[30][10005];

int main() {
	fin >> V >> N;
	for (int i = 1; i <= V; ++i)
		fin >> a[i];
	cnt[0][0] = 1;
	for (int i = 1; i <= V; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (cnt[i - 1][j] != 0) {
				int tmp = j;
				while (tmp <= N) {
					cnt[i][tmp] += cnt[i - 1][j];
					tmp += a[i];
				}
			}
		}
	}
	fout << cnt[V][N] << endl;
	return 0;
}