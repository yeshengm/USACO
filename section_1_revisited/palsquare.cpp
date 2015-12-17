/*
ID: mayeshe1
LANG: C++
PROG: palsquare
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

int B;

int Btrans(int num, int a[]) {
	int bit = 0;
	while (num != 0) {
		a[++bit] = num % B;
		num /= B;
	}
	return bit;
}

void bitPrint(int num) {
	if (num >= 0 && num <= 9) fout << num;
	else if (num >= 10) fout << char ('A' + num - 10);
}

void Palsq(int num) {
	int s[100], t[100];
	int sSize = 0, tSize = 0;
	sSize = Btrans(num, s);
	tSize = Btrans(num * num, t);
	for (int i = 1; i <= tSize / 2; ++i)
		if (t[i] != t[tSize - i + 1])
			return;
	for (int i = sSize; i >= 1; --i)
		bitPrint(s[i]);
	fout << ' ';
	for (int i = 1; i <= tSize; ++i)
		bitPrint(t[i]);
	fout << endl;
}

int main()
{
	fin >> B;
	for (int i = 1; i <= 300; ++i)
		Palsq(i);
	return 0;
}