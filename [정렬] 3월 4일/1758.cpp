#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	long long tip = 0;
	vector<int> exp_tip;

	cin >> n;
	exp_tip.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> exp_tip[i];

	sort(exp_tip.begin(), exp_tip.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		if (exp_tip[i] - i > 0)
			tip += (exp_tip[i] - i);
	}
		
	cout << tip << "\n";
}
