/*
ID: mayeshe1
LANG: C++
PROG: ariprog
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
#define sqr(x) ((x)*(x))
int N, M; //len & bound
bool exist;
bool mark[200000];

int main()
{
	fin >> N >> M;
	for (int i = 0; i <= M; ++i) {
		for (int j = 0; j <= M; ++j) {
			mark[sqr(i)+sqr(j)] = true;
		}
	}
	int maxa = 2*sqr(M);
	int maxb = 2*sqr(M)/(N - 1);
	for (int b = 1; b <= maxb; ++b) {
		for (int a = 0; a <= maxa; ++a) {
			if (a + (N - 1) * b > maxa) break;
			bool flag = true;
			for (int i = 0; i < N; ++i) {
				int tmp = a + i*b;
				if (!mark[tmp]) { flag = false; break; }
			}
			if (flag) { fout << a << ' ' << b << endl; exist = true; }
		}
	}
	if (!exist) fout << "NONE" << endl;
	return 0;
}