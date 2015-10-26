/*
ID: mayeshe1
LANG:C++
TASK: ariprog
*/

/*
note the time limit!
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cmath>
using namespace std;

int N, M;
bool exist = false;
bool isAriprog(int a, int b);
bool isSos(int i);
bool stateSos[2 * 250 * 250 + 10];
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

int main()
{
	
	fin >> N >> M;
	int tmp = 2 * M * M;
	//clock_t start, end;
	
	for (int i = 0; i <= tmp; ++i)
	{
		stateSos[i] = isSos(i);
	}
	//start = clock();
	int abd;
	int bbd = tmp / (N - 1);
	for (int b = 1; b <= bbd; ++b)
		for (int a = 0; a <= tmp - (N - 1) * b; ++a)
			if (!stateSos[a]) //|| a + (N - 1) * b > tmp
				continue;
			else if (isAriprog(a, b))
			{
				//cout << a << ' ' << b << endl;
				fout << a << ' ' << b << endl;
				exist = true;
			}
	//end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	if (!exist) fout << "NONE" << endl;
	//while (1);
	return 0;
}

bool isAriprog(int a, int b)
{
	for (int i = 0; i < N; ++i) {
		if (!stateSos[a + i * b])
			return false;
	}
	return true;
}

bool isSos(int n)
{
	for (int i = 0; i <= sqrt(n/ 2.0); ++i) {
		int remain = n - i * i;
		if (remain > M * M) continue;
		if (sqrt(remain) - (int)(sqrt(remain)) < 0.00000001)
			return true;
	}
	return false;
}