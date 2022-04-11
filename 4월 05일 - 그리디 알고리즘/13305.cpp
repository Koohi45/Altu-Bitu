#include <iostream>
#include <vector>

using namespace std;

long long minCost(vector<int>& dist, vector<int>& liter, int n)
{
	long long m = liter[0];	
	long long answer = m * dist[0];
	for (int i = 1; i < n - 1; i++){
		if (m > liter[i])
			m = liter[i];
		answer += m * dist[i];
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;

	vector<int> distance(n - 1, 0);
	vector<int>	liter(n, 0);
	for (int i = 0; i < n - 1; i++)
		cin >> distance[i];
	for (int i = 0; i < n; i++)
		cin >> liter[i];

	cout << minCost(distance, liter, n) << '\n';
}
