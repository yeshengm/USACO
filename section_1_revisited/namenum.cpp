/*
ID: mayeshe1
LANG: C++
PROG: namenum
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("namenum.in");
ifstream getWord("dict.txt");
ofstream fout("namenum.out");

long long num, bit, numArr[15];
char name[15];
bool found = false;

void getNum(long long num) {
	long long tmp = num;
	while (tmp > 0) { tmp /= 10; bit++; }
	for (int i = bit - 1; i >= 0; --i) {
		numArr[i] = num % 10;
		num /= 10;
	}
}

bool valid() {
	for (int i = 0; i < bit; ++i) {
		if (!((numArr[i] == 2 && (name[i] == 'A' || name[i] == 'B' || name[i] == 'C'))
			|| (numArr[i] == 3 && (name[i] == 'D' || name[i] == 'E' || name[i] == 'F'))
			|| (numArr[i] == 4 && (name[i] == 'G' || name[i] == 'H' || name[i] == 'I'))
			|| (numArr[i] == 5 && (name[i] == 'J' || name[i] == 'K' || name[i] == 'L'))
			|| (numArr[i] == 6 && (name[i] == 'M' || name[i] == 'N' || name[i] == 'O'))
			|| (numArr[i] == 7 && (name[i] == 'P' || name[i] == 'R' || name[i] == 'S'))
			|| (numArr[i] == 8 && (name[i] == 'T' || name[i] == 'U' || name[i] == 'V'))
			|| (numArr[i] == 9 && (name[i] == 'W' || name[i] == 'X' || name[i] == 'Y'))))
			return false;
	}
	if (name[bit] != '\0') return false;
	found = true;
	return true;
}

int main()
{
	fin >> num;
	getNum(num);
	while (getWord >> name) {
		if (valid())
			fout << name << endl;
		for (int i = 0; i < 15; ++i) name[i] = '\0';
	}
	if (!found) fout << "NONE" << endl;
	return 0;
}