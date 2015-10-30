/*
ID: mayeshe1
PROG: ride
LANG: C++
*/
#include "iostream"
#include "fstream"
#include "string"
using namespace std;

int main()
{
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	string ufo, group;
	int iufo = 1, igroup = 1;
	fin >> ufo >> group;
	for (int i = 0; i < ufo.size(); ++i)
	{
		iufo *= (ufo[i] - 'A' + 1);
	}
	for (int i = 0; i < group.size(); ++i)
	{
		igroup *= (group[i] - 'A' + 1);
	}
	if ((igroup % 47) == (iufo % 47))
	{
		fout << "GO" << endl;
	}
	else
	{
		fout << "STAY" << endl;
	}
	return 0;
}