#include <iostream>
#include <vector>
#include "Templates.h"
#include <algorithm>
/*
int main()
{
	using namespace std;
	Pair<int,int> p1, p2, p3;
	
	vector<Pair<int,int> > v;

	cin >> p1 >> p2 >> p3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	sort(v.begin(), v.end());

	vector<Pair<int,int> >::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
	char b;
	cin >> b;
}*/

int main()
{
	using namespace std;
	Pair<char*,char*> p1, p2, p3;

	vector<Pair<char*, char*> > v;

	cin >> p1 >> p2 >> p3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	sort(v.begin(), v.end());

	vector<Pair<char*, char*> >::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
	char b;
	cin >> b;
}
