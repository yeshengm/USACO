/*
ID: mayeshe1
PROG: crypt1
LANG: C++
*/
#include "iostream"
#include "fstream"
#include "stdio.h"
#include "algorithm"
#include "stdlib.h"
using namespace std;
ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

int num[10 + 5];

bool isvalid(int a, int b, int c, int d, int e);
bool isInnum(int n);
int sz, cnt = 0;


int main()
{
	fin >> sz;
	for (int i = 0; i < sz; ++i) {
		fin >> num[i];
	}		//pre-process

	for (int a = 0; a < sz; ++a) {
		for (int b = 0; b < sz; ++b) {
			for (int c = 0; c < sz; ++c) {
				for (int d = 0; d < sz; ++d) {
					for (int e = 0; e < sz; ++e) {
						if (isvalid(num[a], num[b], num[c], num[d], num[e]))
							++cnt;
					}
				}
			}
		}
	}
	fout << cnt << endl;
	return 0;
}

bool isvalid(int a, int b, int c, int d, int e)
{
	int mult1 = 100 * a + 10 * b + c;
	int mult2 = 10 * d + e;
	
	int prod1 = mult1 * e;
	if (prod1 >= 1000 || prod1 < 100) return false;
	if (!isInnum(prod1 % 10)) return false;
	if (!isInnum(prod1 / 100)) return false;
	if (!isInnum((prod1 / 10) % 10)) return false;
	
	int prod2 = mult1 * d;
	if (prod2 >= 1000 || prod2 < 100) return false;
	if (!isInnum(prod2 % 10)) return false;
	if (!isInnum(prod2 / 100)) return false;
	if (!isInnum((prod2 / 10) % 10)) return false;

	int prod = mult1 * mult2;
	if (prod >= 10000 || prod < 1000) return false;
	if (!isInnum(prod % 10)) return false;
	if (!isInnum(prod / 1000)) return false;
	if (!isInnum((prod / 10) % 10)) return false;
	if (!isInnum((prod / 100) % 10)) return false;
	return true;
}

bool isInnum(int n)
{
	for (int i = 0; i < sz; ++i) {
		if (n == num[i])
			return true;
	}
	return false;
}