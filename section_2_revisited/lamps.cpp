/*
ID: mayeshe1
LANG: C++
PROG: lamps
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int N, C;
int t[6], curr[6];
int total[100][6], sz;
bool mark[100];
struct Arr {
	int val;
	int num;
} arr[100];
void init() {
	fin >> N >> C;
	int tmp;
	while (fin >> tmp) {
		if (tmp == -1) break;
		else t[(tmp - 1) % 6] = 1;
	}
	while (fin >> tmp) {
		if (tmp == -1) break;
		else t[(tmp - 1) % 6] = -1;
	}
	for (int i = 0; i < 6; ++i) {
		curr[i] = 1;
	}
}
void op1() {
	for (int i = 0; i < 6; ++i) {
		curr[i] = (curr[i] == 1) ? -1 : 1;
	}
}
void op2() {
	for (int i = 0; i < 6; ++i) {
		if ((i+1)%2 == 1) {
			curr[i] = (curr[i] == 1) ? -1 : 1;
		}
	}
}
void op3() {
	for (int i = 0; i < 6; ++i) {
		if ((i+1)%2 == 0) {
			curr[i] = (curr[i] == 1) ? -1 : 1;
		}
	}
}
void op4() {
	for (int i = 0; i < 6; ++i) {
		if ((i+1)%3 == 1) {
			curr[i] = (curr[i] == 1) ? -1 : 1;
		}
	}
}
int getNum(int a[]) {
	int tmp = 0;
	for (int i = 0; i < 6; ++i) {
		if (a[i] == 1) tmp = tmp * 2 + 1;
		else tmp *= 2;
	}
	return tmp;
}
bool check() {
	if (mark[getNum(curr)]) return false;
	mark[getNum(curr)] = true;
	for (int i = 0; i < 6; ++i) {
		if (curr[i] * t[i] == -1)
			return false;
	}
	for (int i = 0; i < sz; ++i) {
		if (curr[0] == total[i][0] && curr[1] == total[i][1] && curr[2] == total[i][2] &&
			curr[3] == total[i][3] && curr[4] == total[i][4] && curr[5] == total[i][5])
			return false;
	}
	return true;
}
void dfs(int dep) {
	if (dep >= 4 || dep == C) {
		if (check()) {
			for (int i = 0; i < 6; ++i) {
				total[sz][i] = curr[i];
			}
			sz++;
		}
		return;
	}
	op1(); dfs(dep + 1); op1();
	op2(); dfs(dep + 1); op2();
	op3(); dfs(dep + 1); op3();
	op4(); dfs(dep + 1); op4();
}
void swap(Arr &a, Arr &b) {
	Arr tmp = a;
	a = b;
	b = tmp;
}
void arrSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = arr[(s + t) >> 1].val;
	while (i <= j) {
		while (arr[i].val < vmid) ++i;
		while (arr[j].val > vmid) --j;
		if (i <= j) swap(arr[i++], arr[j--]);
	}
	arrSort(s, j);
	arrSort(i, t);
}

int main()
{
	init();
	dfs(0);
	for (int i = 0; i < sz; ++i) {
		arr[i].num = i;
		arr[i].val = getNum(total[i]);
	}
	arrSort(0, sz - 1);
	for (int i = 0; i < sz; ++i) {
		int pos = arr[i].num;
		for (int j = 0; j < N; ++j) {
			fout << (total[pos][j % 6] == 1) ? 1 : 0;
		}
		fout << endl;
	}
	if (sz == 0) fout << "IMPOSSIBLE" << endl;
	return 0;
}