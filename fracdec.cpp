/*
ID: mayeshe1
LANG: C++
PROG: fracdec
*/
#include "iostream"
#include "fstream"
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int N, D;
int yushu[100000];
int shang[100000];
bool exist[100000];
bool find = false;

int getBit(int num) {
	int bit = 0;
	if (num == 0) return 1;
	while (num != 0) {
		num /= 10;
		bit++;
	}
	return bit;
}

int main() {
	std::ios::sync_with_stdio(false);
	fin >> N >> D;
	if (N % D == 0) { fout << N / D << ".0" << endl; return 0; }
	fout << N / D << ".";
	yushu[1] = N % D * 10;
	exist[yushu[1] / 10] = true;
	int weishu = 1;
	int s, t;
	while (1) {
		if (yushu[weishu] == 0) {
			for (int i = 1; i < weishu; ++i) {
				fout << shang[i];
			}
			fout << endl;
			return 0;
		} else if (yushu[weishu] < D) {
			yushu[weishu + 1] = yushu[weishu] * 10;
			shang[weishu] = 0;
		} else if (yushu[weishu] >= D) {
			yushu[weishu + 1] = yushu[weishu] % D * 10;
			shang[weishu] = yushu[weishu] / D;
		}
		if (exist[yushu[weishu + 1] / 10]) {
			for (int i = 1; i <= weishu; ++i) {
				if (yushu[i] == yushu[weishu + 1]) {
					s = i;
					t = weishu;
					find = true;
					break;
				}
			}
		}
		exist[yushu[weishu + 1] / 10] = true;
		if (find) break;
		++weishu;
	}
	int bit = getBit(N / D) + 1;
	for (int i = 1; i <= t; ++i) {
		if (bit == 76) { fout << endl; bit -= 76; }
		if (i == s) { fout << '('; ++bit; }
		if (bit == 76) { fout << endl; bit -= 76; }
		fout << shang[i]; ++bit;
	}
	fout << ")" << endl;
	return 0;
}