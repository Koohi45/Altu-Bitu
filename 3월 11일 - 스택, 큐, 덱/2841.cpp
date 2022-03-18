#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int minFinger(int n, int p)
{
	int line, fret;
	int ans = 0;
	vector<stack<int>> guitar(7);

	for (int i = 0; i < n; i++)
	{
		cin >> line >> fret;
		while (!guitar[line].empty() && guitar[line].top() > fret) {
			ans++;
			guitar[line].pop();
		}
		if (guitar[line].empty() || guitar[line].top() != fret) {
			ans++;
			guitar[line].push(fret);
		}
	}

	return ans;
}

int main()
{
	int n, p;
	cin >> n >> p;

	cout << minFinger(n, p) << "\n";
}