#include <iostream>
#include <vector>

using namespace std;

long long minCost(vector<int>& dist, vector<int>& liter, int n)
{
	long long m = liter[0];	//질문 : m을 최소 liter당 가격이라고 하고 liter당 가격이 최대 1,000,000,000이므로 int로 했는데 백준에서 58점으로 나옵니다. 
							//왜 long long으로 해야 모두 맞았다고 하는지 알 수 있을까요?
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
