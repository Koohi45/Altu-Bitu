#include <iostream>
#include <queue>
#include <string>

using namespace std;

string josephus(int n, int k)
{
	int count = 1;
	string ans = "<";
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(i + 1);

	while (q.size() > 1)
	{
		if (count == k)
		{
			ans += to_string(q.front()) + ", ";
			q.pop();
			count = 1;
		}
		else
		{
			q.push(q.front());
			q.pop();
			count++;
		}
	}
	ans += to_string(q.front()) + ">";

	return ans;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << josephus(n, k) << "\n";
}