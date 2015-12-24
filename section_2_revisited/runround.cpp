/*
ID: mayeshe1
LANG: C++
PROG: runround
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

long long N;
void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
bool check(long long n) {
	int num[15], bit = 0;
	bool mark[15]; for (int i = 0; i < 15; ++i) mark[i] = false;
	while (n != 0) {
		num[bit] = n % 10;
		n /= 10;
		if (num[bit] == 0 || mark[num[bit]] == true) return false;
		else mark[num[bit]] = true;
		bit++;
	}
	for (int i = 0; i <= (bit - 1) / 2; ++i) swap(num[i], num[bit - 1 - i]);
	for (int i = 0; i < 15; ++i) mark[i] = false;
	int pos = 0;
	while (!mark[pos]) {
		mark[pos] = true;
		pos = (pos + num[pos]) % bit;
	}
	if (pos != 0) return false;
	for (int i = 0; i < bit; ++i)
		if (!mark[i])
			return false;
	return true;
}

int main()
{
	fin >> N;
	while (++N) {
		if (check(N)) {
			fout << N << endl;
			return 0;
		}
	}
	return 0;
}