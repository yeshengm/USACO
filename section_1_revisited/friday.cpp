/*
ID: mayeshe1
LANG: C++
TASK: friday
*/
//friday: friday the thirteen

//keep an int passd to store the days passed
//note that there exists Zeller formula (for year > 1582):
//w = (y + [y/4] + [c/4] -2c  + [26(m+1)/10] + d - 1) mod 7
#include <fstream>
using namespace std;
ifstream fin("friday.in");
ofstream fout("friday.out");

int N;
int iweek[7] = { 0 };
int rn[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int pn[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isRn(int N) {
	return (N % 400 == 0) || (N % 4 == 0 && N % 100 != 0);
}

int main()
{
	fin >> N;
	int passd = 0;
	for (int i = 0; i < N; ++i) {
		int iyear = 1900 + i;
		for (int m = 1; m <= 12; m++) {
			int tmpd = passd + 13;
				iweek[tmpd % 7]++;
			if (isRn(iyear)) passd += rn[m];
			if (!isRn(iyear)) passd += pn[m];
		}
		passd %= 7;
	}
	fout << iweek[6] << ' ' << iweek[0];
	for (int i = 1; i <= 5; ++i) fout << ' ' << iweek[i];
	fout << endl;
	return 0;
}