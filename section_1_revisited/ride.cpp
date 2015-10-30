/*
ID: mayeshe1
LANG: C++
PROG: ride
*/

//your ride is here
//ad-hoc problem: simple implementation

#include <fstream>
using namespace std;
ifstream fin("ride.in");
ofstream fout("ride.out");

char src[10], dst[10];

int main()
{
	fin >> src >> dst;
	int isrc = 1, idst = 1;
	for (int i = 0; src[i] != '\0'; ++i)
		isrc *= src[i] - 'A' + 1;
	for (int i = 0; dst[i] != '\0'; ++i)
		idst *= dst[i] - 'A' + 1;
	if ((isrc - idst) % 47 == 0)
		fout << "GO" << endl;
	else fout << "STAY" << endl;
	return 0;
}