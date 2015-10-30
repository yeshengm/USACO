/*
ID: mayeshe1
PROG: beads
LANG: C++
*/
#include "fstream"
using namespace std;

ifstream fin ("beads.in");
ofstream fout ("beads.out");

int cnt(char* a, int n, int ins){
	int cnt = 0, iflag = 1;
	char flag;
	//special cases for all elements are the same
	for (int i = 0; i < n; ++i){
		if (a[i] == 'r') {iflag = 0;  break;}
	}
	if (iflag == 1) return n;
	iflag = 1;
	for (int i = 0; i < n; ++i){
		if (a[i] == 'b') {iflag = 0; break;}
	}
	if (iflag == 1) return n;
	//common cases
	//left case
	for (int i = 1; i <= n; ++i){
		int currNum = (n + ins - i) % n;
		if (a[currNum] != 'w') {flag = a[currNum]; break;}
	}
	for (int i = 1; i <=n; ++i){
		int currNum = (n + ins - i) % n;
		if (a[currNum] != 'w' && a[currNum] != flag) break;
		++cnt; 
	}
	//right case
	int marker, currNum;
	for (int i = 1; i <= n; ++i){
		currNum = (ins + i - 1) % n;
		if (a[currNum] != flag && a[currNum] != 'w') {
			flag = a[currNum]; marker = currNum; break;}
		if (a[currNum] == flag) ++cnt;
		if (a[currNum + 1] != flag && a[currNum + 1] != 'w') {
			flag = a[currNum + 1]; marker = currNum + 1; break;}
	}
	for (int i = 0; i < n; ++i){
		int currNum = (marker + i) % n;
		if (a[currNum] != 'w' && a[currNum] != flag) break;
		++cnt;
	}
	return cnt;
}

int main()
{
	int n = 0, MAX = 0;
	fin >> n;
	char a[n];
	for (int i = 0; i < n; ++i) fin >> a[i];
	for (int i = 0; i < n; ++i)
		if (cnt(a, n, i) > MAX) MAX = cnt(a, n, i);
	if (MAX >= n) fout << n << endl;
	else fout << MAX << endl;
	return 0;
}