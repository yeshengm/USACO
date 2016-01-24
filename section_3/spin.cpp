/*
ID: mayeshe1
LANG: C++
PROG: spin
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out");
bool mark[360], currmark[360];
int speed[5], N[5], t;
vector<int> beg[5], width[5], origin[5];

void changeMark() {
	memset(mark, 1, 360);
	for (int i = 0; i < 5; ++i) {
		memset(currmark, 0, 360);
		for (size_t j = 0; j < beg[i].size(); ++j) {
			int begVal = beg[i][j], endVal = beg[i][j] + width[i][j];
			for (int k = begVal; k <= endVal; ++k) {
				currmark[k % 360] = true;
			}
		}
		for (int k = 0; k < 360; ++k) {
			mark[k] = mark[k] && currmark[k];
		}
	}
}
void updateVal() {
	for (int i = 0; i < 5; ++i) {
		for (size_t j = 0; j < beg[i].size(); ++j) {
			beg[i][j] += speed[i];
			beg[i][j] %= 360;
		}
	}
}
bool isLoop() {
	for (int i = 0; i < 5; ++i) {
		if (origin[i] != beg[i])
			return false;
	}
	return true;
}

int main()
{
	int tmpBeg, tmpWid;
	for (int i = 0; i < 5; ++i) {
		fin >> speed[i] >> N[i];
		for (int j = 0; j < N[i]; ++j) {
			fin >> tmpBeg >> tmpWid;
			beg[i].push_back(tmpBeg);
			width[i].push_back(tmpWid);
		}
	}
	for (int i = 0; i < 5; ++i)
		origin[i] = beg[i];
	for (int t = 0; ; ++t) {
		changeMark();
		for (int i = 0; i < 360; ++i)
			if (mark[i]) {
				fout << t << endl;
				return 0;
			}
		updateVal();
		if (isLoop()) {
			fout << "none" << endl;
			return 0;
		}
	}
	return 0;
}