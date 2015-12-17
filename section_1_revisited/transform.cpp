/*
ID: mayeshe1
LANG: C++
PROG: transform
*/

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("transform.in");
ofstream fout("transform.out");

int N;
char s[15][15], t[15][15];

void swap(char &a, char &b) {
	char tmp = a;
	a = b;
	b = tmp;
}

bool isSame(char tmp[][15]) {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (tmp[i][j] != t[i][j])
				return false;
	return true;
}

void matcpy(char tmp[][15]) {
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = s[i][j];
}

void Spin_90(char tmp[][15]) {
	char mid[15][15];
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			mid[j][N - i + 1] = tmp[i][j];
		}
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = mid[i][j];
}

bool case_1() {
	char tmp[15][15];
	matcpy(tmp);
	Spin_90(tmp);
	return isSame(tmp);
}
bool case_2() {
	char tmp[15][15];
	matcpy(tmp);
	Spin_90(tmp); Spin_90(tmp);
	return isSame(tmp);
}
bool case_3() {
	char tmp[15][15];
	matcpy(tmp);
	Spin_90(tmp); Spin_90(tmp); Spin_90(tmp);
	return isSame(tmp);
}
bool case_4() {
	char tmp[15][15];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = s[i][N - j + 1];
	return isSame(tmp);
}
bool case_5() {
	char tmp[15][15];
	matcpy(tmp);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = s[i][N - j + 1];
	Spin_90(tmp);
	if (isSame(tmp)) return true;
	matcpy(tmp);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = s[i][N - j + 1];
	Spin_90(tmp); Spin_90(tmp);
	if (isSame(tmp)) return true;
	matcpy(tmp);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			tmp[i][j] = s[i][N - j + 1];
	Spin_90(tmp); Spin_90(tmp); Spin_90(tmp);
	if (isSame(tmp)) return true;
	return false;
}
bool case_6() {
	return isSame(s);
}

int main()
{
	fin >> N; fin.get();
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			fin.get(s[i][j]);
		}
		fin.get();
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			fin.get(t[i][j]);
		}
		fin.get();
	}
	if (case_1()) fout << '1';
	else if (case_2()) fout << '2';
	else if (case_3()) fout << '3';
	else if (case_4()) fout << '4';
	else if (case_5()) fout << '5';
	else if (case_6()) fout << '6';
	else fout << '7';
	fout << endl;
	return 0;
}