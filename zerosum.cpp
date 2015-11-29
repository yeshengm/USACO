/*
ID: mayeshe1
LANG: C++
PROG: zerosum
*/
#include "iostream"
#include "fstream"
#include "cstring"
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
#define PLUS 2
#define MINUS 3
#define BLK 1


int N;
int op[10];

bool isValid() {
	int res = 0;
	int formerOp = PLUS;
	int formerNum = 1;
	for (int i = 1; i <= N; ++i) {
		if (op[i] == BLK) {
			formerNum = formerNum * 10 + i + 1;
		}
		if (op[i] != BLK) {
			if (formerOp == PLUS) res += formerNum;
			if (formerOp == MINUS) res -= formerNum;
			formerNum = i + 1;
			formerOp = op[i];
		}
	}
	if (res == 0) return true;
	else return false;
}

void print() {
	for (int i = 1; i <= N - 1; ++i) {
		fout << i;
		if (op[i] == PLUS) fout << "+";
		if (op[i] == MINUS) fout << "-";
		if (op[i] == BLK) fout << " ";
	}
	fout << N;
	fout << endl;
}

void dfs(int bit) {
	if (bit == N) {
		if (isValid())
			print();
		return;
	}
	for (int i = 1; i <= 3; ++i) {
		op[bit] = i;
		dfs(bit + 1);
	}
}

int main()
{
	fin >> N;
	dfs(1);
	return 0;
}