#include <iostream>
#include <vector>

using namespace std;

int maxLength(vector<int>& seq, int n)
{
	int answer = 1;
	vector<int> dp(n, 0);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j] && dp[j] > temp)	
				temp = dp[j];
		}
		dp[i] = temp + 1;
		answer = max(answer, dp[i]);
	}

	return answer;
}

int main()
{
	int n;
	vector<int> seq;

	cin >> n;
	seq.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	cout << maxLength(seq, n) << '\n';
}