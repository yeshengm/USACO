/*
ID: mayeshe1
PROG: gift1
LANG: C++
*/
#include "fstream"
#include "string"
using namespace std;

ifstream fin ("gift1.in");
ofstream fout ("gift1.out");

struct people{
	string name;
	int money;
};

int findPeople(people *friends, string Name){
	for (int i = 0; i < 10; ++i)
		if (Name == friends[i].name)
			return i;
	}

int main()
{
	int size;
	fin >> size;
	people friends[size];
	for (int i = 0; i < size; ++i)
		fin >> friends[i].name;
	for (int i = 0; i < size; ++i)
		friends[i].money = 0;	
	
	for (int i = 0; i < size; ++i)
	{
		string tempName;
		if (!(fin >> tempName))
			break;
		int gift, number;
		fin >> gift >> number;
		if (number == 0)
			continue;
		int giverNumber = findPeople(friends, tempName);
		friends[giverNumber].money += ((gift % number) - gift);
		for (int j = 0; j < number; ++j)
		{	
			string receiverName;
			fin >> receiverName;
			int tempReceiver = findPeople(friends, receiverName);
			friends[tempReceiver].money += (gift / number);
		}
	}
	for (int i = 0; i < size; ++i)
	{
		fout << friends[i].name << " " << friends[i].money << endl;
	}
	return 0;
}