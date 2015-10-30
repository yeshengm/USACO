/*
NAME: mateshe1
PROG: palsquare
LANG: C++
*/
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;
ifstream fin("palsquare.in");
ofstream fout("palsquare.out");

const int MAXNUM = 300;
void palsquare(int i, int step);
void convert(char a[], int step, int num);
bool isPalsquare(char a[]);

int main()
{
	int step;
	fin >> step;
	for (int i = 1; i <= MAXNUM; ++i) {
		palsquare(i, step);
	}
}

void palsquare(int i, int step)
{
	char a[100];
	char sq[100];
	sprintf(a, "%d", i);
	sprintf(sq, "%d", i * i);
	convert(a, step, i);
	convert(sq, step, i * i);
	int sz = strlen(sq);
	int flag;
	for (flag = 0; sq[flag] == sq[sz-1-flag] && flag <sz; ++flag)
		;
	if (flag == sz) {
		fout << a << ' ' << sq << endl;
	}
}

void convert(char a[], int step ,int num)
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