/*
ID: mayeshe1
LANG: C++
PROG: zerosum
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
const int BLK = 0;
const int PLS = 1;
const int MNS = 2;
int N, op[10] = { 0,1,2,1,2,2,1};
int calc() {
	int res = 0, currNum = 1, i = 1, formerOp = BLK;
	for (int i = 1; i <= N -1; ++i) {
		if (op[i] == BLK) {
			currNum = currNum * 10 + i + 1;
		} else if (op[i] == PLS) {
			if (formerOp == BLK) {
				res += currNum;
			} else if (formerOp == PLS) {
				res += currNum;
			} else if (formerOp == MNS) {
				res -= currNum;
			}
			formerOp = PLS;
			currNum = i + 1;
		} else if (op[i] == MNS) {
			if (formerOp == BLK) {
				res += currNum;
			} else if (formerOp == PLS) {
				res += currNum;
			} else if (formerOp == MNS) {
				res -= currNum;
			}
			formerOp = MNS;
			currNum = i + 1;
		}
	}
	if (formerOp == BLK) res = currNum;
	else if (formerOp == PLS) res += currNum;
	else if (formerOp == MNS) res -= currNum;
	return res;
}
void dfs(int dep) {
	if (dep == N - 1) {
		if (calc() == 0) {
			for (int i = 1; i < N; ++i) {
				fout << i;
				if (op[i] == BLK) fout << ' ';
				else if (op[i] == PLS) fout << '+';
				else if (op[i] == MNS) fout << '-';
			}
			fout << N << endl;
		}
		return;
	}
	op[dep + 1] = BLK; dfs(dep + 1);
	op[dep + 1] = PLS; dfs(dep + 1);
	op[dep + 1] = MNS; dfs(dep + 1);
}
int main()
{
	fin >> N;
	dfs(0);
	return 0;
}