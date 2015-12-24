/*
ID: maeyshe1
LANG: C++
PROG: ttwo
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
int a[11][11];
int Rc, Cc, Rfj, Cfj, t, Cdir = UP, FJdir = UP;

void init(){
	char ch;
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			fin.get(ch);
			if (ch == '*')
				a[i][j] = 1;
			else if (ch == 'F')
			{ Rfj = i; Cfj = j; }
			else if (ch == 'C')
			{ Rc = i; Cc = j; }
		}
		fin.get();
	}
}
void changeDir(int &dir) {
	if (dir == UP) dir = RIGHT;
	else if (dir == RIGHT) dir = DOWN;
	else if (dir == DOWN) dir = LEFT;
	else if (dir == LEFT) dir = UP;
}
bool isValid(int x, int y) {
	if (x > 10 || x <= 0 || y <= 0 || y > 10)
		return false;
	if (a[x][y] == 1)
		return false;
	return true;
}
void nextPos(int &x, int &y, int &dir) {
	if (dir == UP) {
		if (isValid(x - 1, y))
			--x;
		else changeDir(dir);
	} else if (dir == RIGHT) {
		if (isValid(x, y + 1))
			++y;
		else changeDir(dir);
	} else if (dir == DOWN) {
		if (isValid(x + 1, y))
			++x;
		else changeDir(dir);
	} else if (dir == LEFT) {
		if (isValid(x, y - 1))
			--y;
		else changeDir(dir);
	}
}

int main()
{
	init();
	while (++t) {
		nextPos(Rc, Cc, Cdir);
		nextPos(Rfj, Cfj, FJdir);
		if (Rc == Rfj && Cc == Cfj) {
			fout << t << endl;
			return 0;
		}
		if (t >= 5000) {
			fout << 0 << endl;
			return 0;
		}
	}
	return 0;
}