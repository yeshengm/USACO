/*
ID: mayesh1
LANG: C++
PROG: milk2
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("milk2.in");
ofstream fout("milk2.out");

int N, marker[1000005], minT =1000005, maxT;
bool milking = false;
int maxMilk, maxNomilk, currMilk, currNomilk;

int main()
{
	int s, t;
	fin >> N;
	for (int i = 0; i < N; ++i) {
		fin >> s >> t;
		for (int j = s; j <= t - 1; ++j)
			marker[j]++;
		minT = (s < minT) ? s : minT;
		maxT = (t - 1 > maxT) ? t - 1 : maxT;
	}
	for (int i = minT; i <= maxT; ++i) {
		if (marker[i] == 0) {
			if (!milking) { ++currNomilk; }
			else if (milking) { 
				milking = false; 
				maxMilk = (currMilk > maxMilk) ? currMilk : maxMilk;
				currMilk = 0;
				++currNomilk;
			}
		} else if (marker[i] != 0) {
			if (milking) { ++currMilk; }
			else if (!milking) {
				milking = true;
				maxNomilk = (currNomilk > maxNomilk) ? currNomilk : maxNomilk;
				currNomilk = 0;
				++currMilk;
			}
		}
	}
	maxMilk = (currMilk > maxMilk) ? currMilk : maxMilk;
	maxNomilk = (currNomilk > maxNomilk) ? currNomilk : maxNomilk;
	fout << maxMilk << ' ' << maxNomilk << endl;
	return 0;
}