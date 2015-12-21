/*
ID: maueshe1
LANG: C++
PROG: milk
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("milk.in");
ofstream fout("milk.out");

struct pack {
	int price;
	int amount;
} packArr[5005];

int M, N, cost;


void swap(pack &a, pack &b) {
	int tmpPrice = a.price;
	int tmpAmout = a.amount;
	a = b;
	b.price = tmpPrice;
	b.amount = tmpAmout;
}

void quickSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = packArr[(s + t) >> 1].price;
	while (i <= j) {
		while (packArr[i].price < vmid) ++i;
		while (packArr[j].price > vmid) --j;
		if (i <= j) swap(packArr[i++], packArr[j--]);
	}
	quickSort(s, j);
	quickSort(i, t);
}

int main()
{
	fin >> M >> N;
	for (int i = 0; i < N; ++i) {
		fin >> packArr[i].price >> packArr[i].amount;
	}
	quickSort(0, N - 1);
	for (int i = 0; i < N; ++i) {
		if (M - packArr[i].amount < 0) {
			cost += M * packArr[i].price;
			break;
		} else if (M - packArr[i].amount >= 0) {
			cost += packArr[i].amount * packArr[i].price;
			M -= packArr[i].amount;
		}
	}
	fout << cost << endl;
	return 0;
}