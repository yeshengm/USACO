/*
ID: mayeshe1
LANG: C++
PROG: fact4
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int N;

int main()
{
	fin >> N;
	int res = 1;
	for (int i = 1; i <= N; ++i) {
		int div = 1, resDiv = 1;
		while (i % div == 0) {
			div *= 5;
			resDiv *= 2;
		}
		div /= 5; resDiv /= 2;
		res = res / resDiv * (i / div);
		res %= 10000;
	}
	fout << res % 10 << endl;
	return 0;
}