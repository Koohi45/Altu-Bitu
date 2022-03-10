#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n)
{
	long long tip = 0;
	vector<int> exp_tip(n, 0);

	//예상 tip 입력
	for (int i = 0; i < n; i++)
		cin >> exp_tip[i];

	sort(exp_tip.begin(), exp_tip.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		if (exp_tip[i] - i > 0)
			tip += (exp_tip[i] - i);
	}

	return tip;
}

int main()
{
	int n;
	
	cin >> n;
			
	cout << calTip(n) << "\n";
}
