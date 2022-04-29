#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, string> ci;

string printCalled(int p, vector<ci>& power)
{
	int left = 0;
	int right = power.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (p <= power[mid].first) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return power[left].second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, p;
	
	cin >> n >> m;
	vector<ci> power(n);
	for (int i = 0; i < n; i++) {
		cin >> power[i].second >> power[i].first;
	}

	while (m--) {
		cin >> p;
		cout << printCalled(p, power) << '\n';
	}
}