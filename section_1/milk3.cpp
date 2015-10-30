/*
NAME: mayeshe1
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");

int A, B, C;
int ia[10000];
int ib[10000];
int ic[10000];
int szcom = 0;
int psb[20];
int szc = 0;

bool existabc(int a, int b, int c);
bool existc(int c);
void traverse(int a, int b, int c);

int main()
{
	fin >> A >> B >> C;
	traverse(0, 0, C);
	sort(psb, psb + szc);
	for (int i = 0; i < szc - 1; ++i)
		fout << psb[i] << ' ';
	fout << psb[szc - 1];
	fout << endl;
	//while (1);
	return 0;
}

void traverse(int a, int b, int c)
{
	if (!existabc(a, b, c)) {
		ia[szcom] = a; ib[szcom] = b; ic[szcom] = c;
		szcom++;
		if (!existc(c) && a == 0) {
			psb[szc++] = c;
		}
	} else
		return;
	if (a != 0 && b != B) {
		if (a <= B - b) traverse(0, a + b, c);
		else traverse(a - (B - b), B, c);
	}
	if (a != 0 && c != C) {
		if (a <= C - c) traverse(0, b, a + c);
		else traverse(a - (C - c), b, C);
	}
	if (b != 0 && a != A) {
		if (b <= A - a) traverse(a + b, 0, c);
		else traverse(A, b - (A - a), c);
	}
	if (b != 0 && c != C) {
		if (b <= C - c) traverse(a, 0, b + c);
		else traverse(a, b - (C - c), C);
	}
	if (c != 0 && a != A) {
		if (c <= A - a) traverse(a + c, b, 0);
		else traverse(A, b, c - (A - a));
	}
	if (c != 0 && b != B) {
		if (c <= B - b) traverse(a, b + c, 0);
		else traverse(a, B, c - (B - b));
	}
}

bool existabc(int a, int b, int c)
{
	for (int i = 0; i < szcom; ++i) {
		if (a == ia[i] && b == ib[i] && c == ic[i])
			return true;
	}
	return false;
}

bool existc(int c)
{
	for (int i = 0; i < szc; ++i)
		if (c == psb[i])
			return true;
	return false;
}