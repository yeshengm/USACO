/*
ID: mayeshe1
LANG: C++
PROG: prefix
*/
#include "string"
#include "fstream"
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");

string elem[205], str;
int len[205];
int elemCnt, strLen;
bool mark[200005];

void check(int i, int j) {
	if (i + len[j] > strLen || mark[i - 1 + len[j]]) 
		return;
	for (int k = 0; k < len[j]; ++k)
		if (elem[j][k] != str[i + k])
			return;
	mark[i - 1 + len[j]] = true;
}

int main()
{
	string tmp;
	while (fin >> tmp)
		if (tmp == ".") break;
		else elem[elemCnt++] = tmp;
	while (fin >> tmp) str += tmp;
	for (int i = 0; i < elemCnt; ++i) len[i] = (elem[i]).size();
	strLen = str.size();
	for (int i = 0; i < strLen; ++i)
		for (int j = 0; j < elemCnt; ++j)
			if (i == 0 || (i >= 1 && mark[i - 1]))
				check(i, j);
	for (int i = strLen - 1; i >= 0; --i)
		if (mark[i]) {
			fout << i + 1 << endl;
			return 0;
		}
	fout << '0' << endl;
	return 0;
}