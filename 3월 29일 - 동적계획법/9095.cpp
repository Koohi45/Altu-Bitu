#include <iostream>
#include <vector>

using namespace std;

int numOfSum(int n)
{
	vector<int> dp(12, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];	
	}

	return dp[n];
}

int main()
{
	int t, n;
	cin >> t;
	
	while (t--) {
		cin >> n;
		cout << numOfSum(n) << '\n';
	}
}