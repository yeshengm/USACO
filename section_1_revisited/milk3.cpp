/*
ID: mayeshe1
LANG: C++
PROG: milk3
*/
#include <iostream>
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
ifstream fin("milk3.in");
ofstream fout("milk3.out");
bool mark[25];
bool state[21][21][21];
int A, B, C;
void find(int a, int b, int c) {
	if (state[a][b][c]) return;
	state[a][b][c] = true;
	if (a == 0) mark[c] = true;
	if (a+b>=B) find(a-(B-b), B, c);
	else find(0, a+b, c);
	if (a+c>=C) find(a-(C-c), b, C);
	else find(0, b, a+c);
	if (b+a>=A) find(A, b-(A-a), c);
	else find(a+b, 0, c);
	if (b+c>=C) find(a, b-(C-c), C);
	else find(a, 0, b+c);
	if (c+a>=A) find(A, b, c-(A-a));
	else find(a+c, b, 0);
	if (c+b>=B) find(a, B, c-(B-b));
	else find(a, b+c, 0);
}

int main()
{
	fin >> A >> B >> C;
	find(0, 0, C);
	int i;
	for (i = 0; i <= 20; ++i) 
		if (mark[i]) { fout << i; break; }
	for (++i; i <= 20; ++i) {
		if (mark[i]) {
			fout << ' ' << i;
		}
	}
	fout << endl;
	return 0;
}