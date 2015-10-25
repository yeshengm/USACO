/*
ID: mayeshe1
PROG: friday
LANG: C++
*/
#include "fstream"
using namespace std;

ifstream fin ("friday.in");
ofstream fout ("friday.out");

//judge whether it is a leap year
bool isLeap(int n){  
	if (n % 400 == 100) return true;
		else if (n % 100 == 0) return false;
			else if (n % 4 == 0) return true;
				else return false;
}

int main()
{
	int N,number = 0;
	fin >> N;
	int counter[7] = {0};
	for (int i = 0; i < N; ++i){
		if (isLeap(i)) {
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 1;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
		}
		if (!isLeap(i)) {
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 0;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
			counter[number % 7]++; number += 2;
			counter[number % 7]++; number += 3;
		}
		number %= 7;
	}
	for (int i = 0; i < 6; i++){
		fout << counter[i] << " ";
	}
	fout  << counter[6]<< endl;
	return 0;
}
