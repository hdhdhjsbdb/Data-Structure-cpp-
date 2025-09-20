//≈–∂œ¿®∫≈∆•≈‰À„∑®
#include<iostream>
#include<cstring>
#include"SeqStack.h"
using namespace std;
const int maxLength = 100;

void PrintMatchPairs(char* expression)
{
	SeqStack<int> s(maxLength);
	int j, length = strlen(expression);
	for (int i = 1; i <= length; i++)
	{
		if (expression[i - 1] == '(') s.Push(i);
		else if (expression[i - 1] == ')')
		{
			if (!s.IsEmpty() && s.Pop(j))
				cout << j << "match" << i << endl;
			else
				cout << "√ª”–”Îµ⁄" << i << "∏ˆ”“¿®∫≈∆•≈‰µƒ◊Û¿®∫≈" << endl;
		}
	}
	while (!s.IsEmpty())
	{
		s.Pop(j);
		cout << "√ª”–”Îµ⁄" << j << "∏ˆ◊Û¿®∫≈∆•≈‰µƒ”“¿®∫≈" << endl;
	}
}

int main()
{
	char exp[maxLength];
	cin >> exp;
	PrintMatchPairs(exp);

	system("pause");
	return 0;
}