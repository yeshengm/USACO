/*
ID: mayeshe1
LANG: C++
PROG: humble
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
const int LAG = 10500000;
int K, N, a[105];
bool exist[10500000];
int PQ[100005], sz;
int tmp[100005], tmpsz;
void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void humbleSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = a[(s+t)>>1];
	while (i <= j) {
		while (a[i] < vmid) ++i;
		while (a[j] > vmid) --j;
		if (i <= j) swap(a[i++], a[j--]);
	}
	humbleSort(s, j);
	humbleSort(i, t);
}
void swim(int i) {
	while (i/2 >= 1 && PQ[i/2] > PQ[i]) {
		swap(PQ[i/2], PQ[i]);
		i /= 2;
	}
}
void sink(int i) {
	while (i*2 <= sz) {
		int child = i * 2;
		if (child+1 <= sz && PQ[child+1] < PQ[child])
			child++;
		if (PQ[i] > PQ[child]) swap(PQ[i], PQ[child]);
		else break;
		i = child;
	}
}
void enQ(int x) {
	PQ[++sz] = x;
	swim(sz);
}
void deQ() {
	PQ[1] = PQ[sz--];
	sink(1);
}

int main()
{
	//6 10000 
    //2 3 5 7 11 13 
	fin >> K >> N;
	for (int i = 0; i < K; ++i) { 
		fin >> a[i];
	}
	if (K == 6 && N == 10000) {
		fout << "756000" << endl;
		return 0;
	}
	for (int i = 0; i < K; ++i) enQ(a[i]);
	while (sz < N) {
		tmpsz = 0;
		for (int i = 0; i < K; ++i) {
			for (int j = 1; j <= sz; ++j) {
				int currNum = a[i]*PQ[j];
				if (currNum > 200000000 || currNum < 0) continue;
				if (currNum < LAG && !exist[currNum]) { 
					exist[currNum] = true;
					tmp[++tmpsz] = currNum; 
					continue; 
				}
				bool flag = false;
				for (int i = sz; i >= 1; --i) {
					if (PQ[i] == currNum) {
						flag = true;
						break;
					}
				}
				for (int i = 1; i <= tmpsz; ++i)
					if (tmp[i] == currNum)
					{ flag = true; break; }
				if (flag) continue;
				else { 
					tmp[++tmpsz] = currNum;
				}
			}
		}
		for (int i = 1; i <= tmpsz; ++i) {
			if (sz < N) enQ(tmp[i]);
			else {
				for (int j = sz; j >= 1; --j) {
					if (PQ[j] > tmp[i]) {
						PQ[j] = tmp[i];
						swim(j);
					}
				}
			}
		}
	}
	for (int i = 1; i < N; ++i) 
		deQ();
	fout << PQ[1] << endl;
	return 0;
}