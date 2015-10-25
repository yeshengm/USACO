/*
ID: mayeshe1
PROG: namenum
LANG: C++
*/ 
#include "iostream"
#include "fstream"
#include "string"
#include "cmath"
using namespace std;
ifstream fin("namenum.in");
ifstream textin("dict.txt");
ofstream fout("namenum.out");

char key[200];
char num[20];
char name[20];
int found = 0;

int main()
{
	key['A'] = key['B'] = key['C'] = '2'; //init
    key['D'] = key['E'] = key['F'] = '3';
    key['G'] = key['H'] = key['I'] = '4';
    key['J'] = key['K'] = key['L'] = '5';
    key['M'] = key['N'] = key['O'] = '6';
    key['P'] = key['R'] = key['S'] = '7';
    key['T'] = key['U'] = key['V'] = '8';
    key['W'] = key['X'] = key['Y'] = '9';
    fin >> num;
    while (textin >> name) {
    	int i, j;
    	i = j = 0;
    	while (key[name[i]] == num[j] && num[j]!='\0' && name[i]!='\0') {
    		++i;
    		++j;
    	}
    	if (name[i]=='\0' && num[j]=='\0') {
    		fout << name << endl;
    		found = 1;
    	}
    }
    if (!found) {
    	fout <<"NONE" <<endl;
    }
	return 0;
}