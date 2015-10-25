/*
ID: mayeshe1
PROG: transform
LANG: C++
*/
#include "fstream"
using namespace std;

ifstream fin ("transform.in");
ofstream fout ("transform.out");

void giveValue(char a[][10], char judge[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) judge[i][j] = a[i][j];
	}
}
void reflect(char judge[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < (N/2); ++j){
			char temp = judge[i][j];
			judge[i][j] = judge[i][N - j - 1];
			judge[i][N - j - 1] = temp;
		}
	}
}

void rotate(char judge[][10], int N){
 	char c[10][10];
 	for (int i = 0; i < N; ++i){
 		for (int j = 0; j < N; j++)	c[i][j] = judge[j][i]; 
 	}
 	for (int i = 0; i < N; ++i){
		for (int j = 0; j < (N/2); ++j){
			char temp = c[i][j];
			c[i][j] = c[i][N - j - 1];
			c[i][N - j - 1] = temp;
		}
	}
	for (int i = 0; i < N; ++i){
 		for (int j = 0; j < N; j++)	 judge[i][j] = c[i][j]; 
 	}
}

bool cmp(char a[][10], char b[][10], int N){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (a[i][j] != b[i][j])	return false;
		}
	}
	return true;
}

int main()
{
	char a[10][10], judge[10][10], b[10][10];
	int N;
	fin >> N;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) fin >> a[i][j];
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) fin >> b[i][j];
	}
	giveValue(a, judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '1' << endl; return 0;}
	
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '2' << endl; return 0;}
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '3' << endl; return 0;}
	
	giveValue(a, judge, N); reflect(judge, N); if (cmp(b,judge,N)) {fout << '4' << endl; return 0;}
	
	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '5' << endl; return 0;}
	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '5' << endl; return 0;}
	giveValue(a, judge, N); reflect(judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); if (cmp(b,judge,N)) {fout << '5' << endl; return 0;}
	
	giveValue(a, judge, N); if (cmp(b,judge, N)) {fout << '6' << endl; return 0;}
	
	giveValue(a, judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b,judge,N)) {fout << '11' << endl; return 0;}
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b,judge,N)) {fout << '12' << endl; return 0;}
	giveValue(a, judge, N); rotate(judge, N); rotate(judge, N); rotate(judge, N); reflect(judge, N); if (cmp(b,judge,N)) {fout << '13' << endl; return 0;}

	fout << '7' << endl; return 0;
}