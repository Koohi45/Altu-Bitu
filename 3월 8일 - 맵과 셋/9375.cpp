#include <iostream>
#include <map>

using namespace std;

int numCloth(int n)
{
	int ans = 1;
	string cloth, type;
	map<string, int> cl;

	while (n--)
	{
		cin >> cloth >> type;
		cl[type]++;
	}

	for (auto iter = cl.begin(); iter != cl.end(); iter++)
	{
		ans *= (iter->second + 1);	//옷의 종류 + 1(안 입은 경우)
	}

	return ans - 1;	//전부 안 입은 경우 빼기
}

int main()
{
	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		cout << numCloth(n) << "\n";
	}
}
