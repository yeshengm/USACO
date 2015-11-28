/*
ID: mayeshe1
LANG: C++
PROG: preface
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");

int N;

int I[5][20] = {{}, {0, 1, 2, 3, 1, 0, 1, 2, 3, 1}};
int V[5][20] = {{}, {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};
int X[5][20] = {{}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 2, 3, 1, 0, 1, 2, 3, 1}};
int L[5][20] = {{}, {}, {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};
int C[5][20] = {{}, {}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 2, 3, 1, 0, 1, 2, 3, 1}};
int D[5][20] = {{}, {}, {}, {0, 0, 0, 0, 1, 1, 1, 1, 1, 0}};
int M[5][20] = {{}, {}, {}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 2, 3}};

int cnt[10];

void calc(int num)
{
    for (int a = 0; a <= 9; ++a)
    for (int b = 0; b <= 9; ++b)
    for (int c = 0; c <= 9; ++c)
    for (int d = 0; d <= 3; ++d)
    {
        int sum = d* 1000 + c * 100 + b * 10 + a;
        if (sum == num)
        {
            cnt[1] += I[1][a];
            cnt[2] += V[1][a];
            cnt[3] += X[1][a] + X[2][b];
            cnt[4] += L[2][b];
            cnt[5] += C[2][b] + C[3][c];
            cnt[6] += D[3][c];
            cnt[7] += M[3][c] + M[4][d];
            return;
        }
    }
}

int main()
{
    fin >> N;
    for (int i = 1; i <= N; ++i) calc(i);
    if (cnt[1] != 0) fout << "I" << ' ' << cnt[1] << endl;
    if (cnt[2] != 0) fout << "V" << ' ' << cnt[2] << endl;
    if (cnt[3] != 0) fout << "X" << ' ' << cnt[3] << endl;
    if (cnt[4] != 0) fout << "L" << ' ' << cnt[4] << endl;
    if (cnt[5] != 0) fout << "C" << ' ' << cnt[5] << endl;
    if (cnt[6] != 0) fout << "D" << ' ' << cnt[6] << endl;
    if (cnt[7] != 0) fout << "M" << ' ' << cnt[7] << endl;
    return 0;
}
