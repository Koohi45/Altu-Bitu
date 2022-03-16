#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minFinger(int n, int p)
{
	int line, fret;
	int ans = 0;
	vector<stack<int>> st_vec(6);

	for (int i = 0; i < n; i++)
	{
		cin >> line >> fret;
		while (!st_vec[line - 1].empty())
		{
			if (st_vec[line - 1].top() <= fret)
				break;

			st_vec[line - 1].pop();
			ans++;
		}

		if (!st_vec[line - 1].empty() && st_vec[line - 1].top() == fret)
			continue;

		st_vec[line - 1].push(fret);
		ans++;
	}

	return ans;
}

int main()
{
	int n, p;
	cin >> n >> p;

	cout << minFinger(n, p) << "\n";
}