/*
ID: mayeshe1
PROG: milk
LANG: C++
*/
#include "iostream"
#include "fstream"
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");
#define MAXNUM 5100
int main()
{
	int N, M, amount, cost;  //init
	amount = cost = 0;
	fin >> N >> M;
	int  P[MAXNUM], A[MAXNUM], USE[MAXNUM];
	for (int i = 0; i < M; ++i) {  
		fin >> P[i] >> A[i];
		USE[i] = 0;
	}
	int nmax = 0;
	for (int i = 0; i < M; ++i) {
		if (P[i] > P[nmax])
			nmax = i;
	}
	while (1) {
		if (N == 0)
			break;
		int i, nmin;
		i = 0;
		nmin = nmax;
		for (i = 0; i < M; ++i) {
			if (P[i] <= P[nmin] && !USE[i]) {
				nmin = i;
			}
		}
		USE[nmin] = 1;
		if (amount + A[nmin] <= N) {
			cost += A[nmin] * P[nmin]; 
			amount += A[nmin];
		} else {
			cost += (N - amount) * P[nmin];
			break;
		}
	}
	if (N == 0) {
		fout << 0 << endl;
	} else {
		fout << cost << endl;
	}
	return 0;
}