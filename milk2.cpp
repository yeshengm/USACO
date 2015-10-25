/*
ID: mayeshe1
PROG: transform
LANG: C++
*/
#include "fstream"
using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

void giveValue(int a[][10], int judge[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) judge[i][j] = a[i][j];
	}
}
void reflect(int judge[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < (N / 2); ++j){
			int temp = judge[i][j];
			judge[i][j] = judge[i][N - j - 1];
			judge[i][N - j - 1] = temp;
		}
	}
}

void rotate(int judge[][10], int N){
	int c[10][10];
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; j++)	c[i][j] = judge[j][i];
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < (N / 2); ++j){
			int temp = c[i][j];
			c[i][j] = c[i][N - j - 1];
			c[i][N - j - 1] = temp;
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; j++)	 judge[j][i] = c[i][j];
	}
}

bool cmp(int a[][10], int b[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (a[i][j] != b[i][j])	return false;
		}
	}
	return true;
}

int main()
{
	int a[10][10], N, judge[10][10], b[10][10];
	fin >> N;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) fin >> a[i][j];
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) fin >> b[i][j];
	}
	giveValue(a, judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '1' << endl; return 0; }

	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '2' << endl; return 0; }
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '3' << endl; return 0; }

	giveValue(a, judge, N); reflect(judge, N); if (cmp(b, judge, N)) { fout << '4' << endl; return 0; }

	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '5' << endl; return 0; }
	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '5' << endl; return 0; }
	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b, judge, N)) { fout << '5' << endl; return 0; }

	giveValue(a, judge, N); if (cmp(b, judge, N)) { fout << '6' << endl; return 0; }

	giveValue(a, judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b, judge, N)) { fout << '11' << endl; return 0; }
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b, judge, N)) { fout << '12' << endl; return 0; }
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b, judge, N)) { fout << '13' << endl; return 0; }

	fout << '7' << endl; return 0;
}