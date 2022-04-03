#include <iostream>
#include <vector>

using namespace std;

int rectangularTile(int n)
{
	vector<int> dp(n + 1, 0);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		//직사각형의 가로를 (1, n - 1), (2, n - 2)로 나누어서 생각하여 더해준다.
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	
	cout << rectangularTile(n) << '\n';
}