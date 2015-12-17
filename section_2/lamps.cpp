/*
ID: mayeshe1
LANG: C++
PROG: lamps
*/
#include <fstream>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");

int N, C;
int onCnt, offCnt;
bool flag = false;
int onPos[101], offPos[101];
int caseName[10][10] = {{0}, {1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0} ,{0, 1, 1, 0, 1, 1}, {1, 0, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 1}, {0, 0, 1, 1, 1, 0}};

void judge(int caseNum)
{
    for (int i = 0; i < onCnt; ++i) {
        int tmp = (onPos[i] - 1) % 6;
        if (caseName[caseNum][tmp] != 1)
            return;
    }
    for (int i = 0; i < offCnt; ++i) {
        int tmp = (offPos[i] - 1) % 6;
        if (caseName[caseNum][tmp] != 0)
            return;
    }
    for (int i = 0; i < N; ++i) fout << caseName[caseNum][i % 6];
    fout << endl;
    flag = true;
}

int main()
{
    fin >> N >> C;
    for (int i = 0; i < 105; ++i) {
        int tmp; fin >> tmp;
        if (tmp == -1)
            break;
        else {onPos[i] = tmp; ++onCnt;}
    }
    for (int i = 0; i < 105; ++i) {
        int tmp; fin >> tmp;
        if (tmp == -1)
            break;
        else {offPos[i] = tmp; ++offCnt;}
    }
    while (C > 4) C -= 2;
    if (C == 0)
        if (offCnt != 0) {fout << "IMPOSSIBLE" << endl; return 0;}
        else {for (int i = 0; i < N; ++i) fout << "1"; fout << endl; return 0;}
    else if (C == 1) {judge(2); judge(3); judge(5); judge(4);}
    else if (C == 2) {judge(2); judge(8); judge(3); judge(6); judge(4); judge(7);}
    else if (C >= 3) { judge(2); judge(8); judge(3); judge(5); judge(6); judge(4); judge(7); judge(1);}
    if (flag == false) fout << "IMPOSSIBLE" << endl;
    return 0;
}
