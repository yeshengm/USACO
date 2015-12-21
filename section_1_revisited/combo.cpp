/*
ID: mayeshe1
LANG: C++
PROG: combo
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("combo.in");
ofstream fout("combo.out");

int fjpsw[5], setpsw[5], N, cnt;
int psw[300][5];

int lockRound(int num) {
	if (num >= 1 && num <= N) return num;
	else if (num <= 0) { while (num <= 0) num += N; return num;}
	else if (num > N) { while (num > N) num -= N; return num; }
}

void insFJ(int i, int j, int k) {
	int a, b, c;
	bool used = false;
	a = lockRound(fjpsw[1] + i); b = lockRound(fjpsw[2] + j); c = lockRound(fjpsw[3] + k);
	for (int i = 1; i <= cnt; ++i) {
		if (a == psw[i][1] && b == psw[i][2] && c == psw[i][3])
			return;
	}
	++cnt;
	psw[cnt][1] = a; psw[cnt][2] = b; psw[cnt][3] = c;
}

void insSet(int i, int j, int k) {
	int a, b, c;
	bool used = false;
	a = lockRound(setpsw[1] + i); b = lockRound(setpsw[2] + j); c = lockRound(setpsw[3] + k);
	for (int i = 1; i <= cnt; ++i) {
		if (a == psw[i][1] && b == psw[i][2] && c == psw[i][3])
			return;
	}
	++cnt;
	psw[cnt][1] = a; psw[cnt][2] = b; psw[cnt][3] = c;
}


int main()
{
	fin >> N;
	for (int i = 1; i <= 3; ++i) fin >> fjpsw[i];
	for (int i = 1; i <= 3; ++i) fin >> setpsw[i];
	for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
			for (int k = -2; k <= 2; ++k) {
				insFJ(i, j, k);
				insSet(i, j, k);
			}
		}
	}
	fout << cnt << endl;
	return 0;
}