#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("1.txt");

struct point {
	int row, col, val;
	int next;
} p[10001];
int N, M, opn, op, head[1000001];
void init() {
	fin >> N;
	for (int i = 1; i <= N; ++i) {
		fin >> p[i].row >> p[i].col >> p[i].val;
		p[i].next = head[p[i].row];
		head[p[i].row] = i;
	}
	fin >> M;
	fin >> opn;
}
void swapRow(int x, int y) {};
void swapCol(int x, int y) {};
void assignVal(int x, int y) {};

int main()
{
	
	int x, y;
	for (int i = 0; i < opn; ++i) {
		fin >> op >> x >> y;
		if (op == 0) swapRow(x, y);
		else if (op == 1) swapCol(x, y);
		else if (op == 2) assignVal(x, y);
	}
	return 0;
}