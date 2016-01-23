/*
ID: mayesheng
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int INF = 0xfffffff;
ifstream fin("stamps.in");
ofstream fout("stamps.out");

int K, N, a[10005];   //K totalNum 200, N categories 50
int dp[2000001];

int main() 
{
	fin >> K >> N;
	for (int i = 0; i < N; ++i)
		fin >> a[i];
	sort(a, a + N);
	dp[0] = 0;
	for (int i = 1; i <= K * a[N - 1] + 1; ++i)
		dp[i] = INF;
	for (int i = 0; dp[i] <= K; ++i) {
		for (int j = 0; j < N && dp[i] != K; ++j) {
			dp[i + a[j]] = (dp[i] + 1 < dp[i + a[j]]) ? dp[i] + 1 : dp[i + a[j]];
		}
	}
	for (int i = 1; ; ++i) {
		if (dp[i] > K) {
			fout << i - 1 << endl;
			break;
		}
	}
	return 0;
}