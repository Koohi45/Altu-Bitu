#include <iostream>
#include <vector>

using namespace std;

int n, minimum = 1e8;
vector<vector<int>> cost(10, vector<int>(10));
vector<int> path(10, 0);
vector<bool> check(10, false);

void backtracking(int cnt)
{
	if (cnt == n) {
		int c = 0;
		for (int i = 0; i < n - 1; i++) {
			if (cost[path[i]][path[i + 1]] == 0)
				return;
			c += cost[path[i]][path[i + 1]];
		}
		if (cost[path[n - 1]][path[0]] == 0)
			return;
		c += cost[path[n - 1]][path[0]];
		minimum = min(minimum, c);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			path[cnt] = i;
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	backtracking(0);
	cout << minimum << '\n';
}
