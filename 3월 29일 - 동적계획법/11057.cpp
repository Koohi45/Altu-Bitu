#include <iostream>
#include <vector>

using namespace std;

int ascending(int n)
{
	int answer = 0;
	vector<vector<int>> dp(n + 1, vector<int>(10, 1));
	/*
	*i는 길이, j는 길이가 i인 수의 마지막 숫자
	*dp[i][j]의 값은 dp[i-1][0]~dp[i-1][j]까지의 합
	*dp[i-1][j-1]까지의 합이 dp[i][j-1]에 저장
	*/
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	for (int i = 0; i < 10; i++)
		answer += dp[n][i];

	return answer % 10007;
}

int main()
{
	int n;
	cin >> n;

	cout << ascending(n) << '\n';
}