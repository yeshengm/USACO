/*
ID: mayehse1
PROG: dualpal
LANG: C++
*/
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

int N, s;
bool isDualpal(int s);
bool isPal(int s, int step);
void convert(char *a, int step ,int num);

int main()
{
	fin >> N >> s;
	int ndualpal;
	++s;
	for (ndualpal = 0; ndualpal < N; ++s) {
		if (isDualpal(s)) {
			fout << s << endl;
			++ndualpal;
		}
	}
	return 0;
}

bool isDualpal(int s)
{
	int cnt = 0;
	for (int i = 2; i <= 10; ++i) {
		if (isPal(s, i))
			++cnt;
		if (cnt >= 2)
			return true;
	}
	return false;
}

bool isPal(int s, int step)
{
	char str[1000];
	convert(str, step, s);
	char *end, *start = str;
	for (end = start + strlen(str) - 1; start < end; ++start, --end) {
		if (*start != *end)
			return false;
	}
	return true;
}

void convert(char *a, int step ,int num)
{
	char temp[1000];
	int i;
	for (i = 0; num != 0; ++i) {
		switch (num % step) {
			case 0: case 1: case 2: case 3: case 4: case 5:
			case 6: case 7: case 8: case 9:
				temp[i] = num % step + '0';
				break;
			case 10: case 11: case 12: case 13: case 14: case 15:
			case 16: case 17: case 18: case 19: case 20:
			 temp[i] = num % step - 10 + 'A';
		}
		num /= step;
	}
	for (int j = 0; j < i; ++j) {
		a[j] = temp[i-1-j];
		a[j+1] = '\0';
	}
}