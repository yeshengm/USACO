/*
ID: mayeshe1
LANG: C++
PROG: crypt1
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

int N, cnt;
bool a[10];

bool valid(int num) {
	while (num != 0) {
		if (!a[num % 10]) return false;
		num /= 10;
	}
	return true;
}

int main()
{
	fin >> N;
	int tmp;
	for (int i = 0; i < N; ++i) { fin >> tmp; a[tmp] = true; }
	for (int i = 100; i <= 999; ++i) {
		for (int j = 10; j <= 99; ++j) {
			int num1, num2, pro;
			num1 = i * (j % 10);
			num2 = i * (j / 10);
			pro = i * j;
			if (num1 >= 1000 || num2 >= 1000 || pro >= 10000) continue;
			if (!valid(i) || !valid(j) || !valid(num1) || !valid(num2) || !valid(pro)) continue;
			++cnt;
		}
	}
	fout << cnt << endl;
	return 0;
}