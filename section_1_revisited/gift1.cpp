/*
ID: mayeshe1
LANG: C++
PROG: gift1
*/
//gift1: greedy gift givers

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("gift1.in");
ofstream fout("gift1.out");

struct giver {
	char name[15];
	int give = 0;
	int receive = 0;
};

int N;
giver ggiver[12];

bool strcmp(char *s1, char *s2) {
	while (*(s1++) == *(s2++))
		if (*s1 == '\0' && *s2 == '\0')
			return true;
	return false;
}
void modifyGiver(char *name, int tmprcvn, int tmpmoney) {
	if (tmpmoney == 0 || tmprcvn == 0) return;
	for (int i = 0; i < N; ++i)
		if (strcmp(name, ggiver[i].name)) {
			ggiver[i].give += tmpmoney - tmpmoney % tmprcvn;
			return;
		}
}
void modifyRcv(char *name, int tmprcvn, int tmpmoney) {
	for (int i = 0; i < N; ++i)
		if (strcmp(name, ggiver[i].name)) {
			ggiver[i].receive += tmpmoney / tmprcvn;
			return;
		}
}

int main()
{
	fin >> N;
	for (int i = 0; i < N; ++i)
		fin >> ggiver[i].name;

	char tmpgiver[15];
	int tmpmoney, tmprcvn;
	char tmprcv[15];
	while (fin >> tmpgiver) {
		fin >> tmpmoney >> tmprcvn;
		modifyGiver(tmpgiver, tmprcvn, tmpmoney);
		for (int i = 0; i < tmprcvn; ++i) {
			fin >> tmprcv;
			modifyRcv(tmprcv, tmprcvn, tmpmoney);
		}
	}
	for (int i = 0; i < N; ++i)
		fout << ggiver[i].name << ' ' 
		<< (ggiver[i].receive - ggiver[i].give) << endl;
	//while (1);
	return 0;
}