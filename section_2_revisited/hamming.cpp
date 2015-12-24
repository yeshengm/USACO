/*
ID: mayeshe1
LANG: C++
PROG: hamming
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("hamming.in");
ofstream fout("hamming.out");

int N, B, D; //N ge, B wei, D juli
int ham[70][10], sz, tmp[10];

void check() {
	bool flag = true;;
	for (int i = 1; i <= B; ++i) {
		if (tmp[i] != 0) {
			flag = false;
			break;
		}
	}
	if (flag) {
		for (int i = 1; i <= B; ++i) {
			ham[0][i] = 0;
		}
		sz++;
		return;
	}
	for (int i = 0; i < sz; ++i) {
		int cnt = 0;
		for (int j = 1; j <= B; ++j) {
			if (tmp[j] != ham[i][j])
				++cnt;
		}
		if (cnt < D) return;
	}
	for (int i = 1; i <= B; ++i)
		ham[sz][i] = tmp[i];
	sz++;
}
void find(int dep) {
	if (sz >= N) return;
	if (dep == B) {
		check();
		return;
	}
	tmp[dep + 1] = 0;
	find(dep + 1);
	tmp[dep + 1] = 1;
	find(dep + 1);
}
int getNum(int a[]) {
	int tmp = 0;
	for (int i = 1; i <= B; ++i) {
		tmp = 2*tmp + a[i];
	}
	return tmp;
}
int main()
{
	fin >> N >> B >> D;
	find(0);
	int currCnt = 0;
	for (int i = 0; i < N - 1; ++i) {
		++currCnt;
		if (currCnt % 10 == 0) fout << getNum(ham[i]) << endl;
		else fout << getNum(ham[i]) << ' ';
	}
	fout << getNum(ham[N -1]) << endl;
	return 0;
}