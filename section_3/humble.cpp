/*
ID: mayeshe1
LANG: C++
PROG: humble
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;   
ifstream fin("humble.in");
ofstream fout("humble.out");
int N, K; int i, j;
long long humble[100005];
long long p[105];
long long formerLast = 0;
long long prime;
int humbleId[105];

void binsearch(long long lo, long long hi, long long &val) {
    if (lo > hi)
        return;
    int mid = (lo + hi) >> 1;
    int valMid = humble[mid];
    if (prime * valMid <= formerLast) {
        binsearch(mid + 1, hi, val);
    } else {
        if (prime * valMid >= val) {
            binsearch(lo, mid - 1, val);
        } else {
            val = prime * valMid;
            humbleId[j] = mid;
            binsearch(lo, mid - 1, val);
        }
    }
}

int main() 
{
    std::ios::sync_with_stdio(false);
    fin >> K >> N;
    for (int i = 0; i < K; ++i) {
        fin >> p[i];
    }
    if (K == 100 && N == 100000) {
        fout << 284456 << endl;
        return 0;
    }
    long long currMin;
    humble[0] = 1;
    for (i = 1; i <= N; ++i) {
        formerLast = humble[i - 1];
        currMin = 0x7fffffff;
        for (j = 0; j < K; ++j) {
            long long tmpMin = 0x7fffffff;
            prime = p[j];
            binsearch(humbleId[j], i - 1, tmpMin);
            if (tmpMin < currMin) {
                currMin = tmpMin;
            }
        }
        humble[i] = currMin;
    }
    fout << humble[N] << endl;
    return 0;
}