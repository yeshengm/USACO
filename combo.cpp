/*
ID: mayeshe1
PROG: combo
LANG: C++
*/
#include "iostream"
#include "fstream"
#include "cmath"
using namespace std;
ifstream fin("combo.in");
ofstream fout("combo.out");

int N, a1, a2, a3, b1, b2, b3;

bool canOpenFarmer(int i, int j, int k);
bool canOpenMaster(int i, int j, int k);
bool isNear(int n, int locknum);

int main()
{
	fin >> N >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
	int cnt = 0;	//pre-process

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				if (canOpenFarmer(i,j,k) || canOpenMaster(i,j,k))
					++cnt;
			}
		}
	}
	fout << cnt << endl;
	return 0;
}

bool isNear(int n, int locknum)
{
	int leap = abs(n - locknum);
	if (leap <= 2 || N-leap <=2) 
		return true;
	return false;
}

bool canOpenFarmer(int i, int j, int k)
{
	if (isNear(i, a1) && isNear(j, a2) && isNear(k, a3))
		return true;
	return false;
}

bool canOpenMaster(int i, int j, int k)
{
	if (isNear(i, b1) && isNear(j, b2) && isNear(k, b3))
		return true;
	return false;
}