#include <iostream>
#include <vector>

using namespace std;

int maxSushi(vector<int> &s, int n, int d, int k, int c)
{
	int ans = 0;
	int m = 0;

	for (int i = 0; i < n; i++) {
		vector<bool> check(d + 1, false);
		m = 0;
		for (int j = 0; j < k; j++) {
			if (check[s[(i + j) % n]])	continue;
			check[s[(i + j) % n]] = true;
			m++;
		}
		if (!check[c])
			m++;
		ans = max(ans, m);
	}

	return ans;
}

int main()
{
	int n, d, k, c;
	vector<int> sushi;

	cin >> n >> d >> k >> c;
	sushi.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> sushi[i];

	cout << maxSushi(sushi, n, d, k, c) << '\n';
}
