#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int compute(int a, int b) 
{
	int ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a;
		ans %= 10;
	}
	
	if (ans == 0)
		return 10;

	return ans;
}

int main()
{
	int t;
	vector<ci> data;

	cin >> t;
	data.assign(t, { 0, 0 });
	for (int i = 0; i < t; i++) {
		cin >> data[i].first >> data[i].second;
		cout << compute(data[i].first, data[i].second) << "\n";
	}
}