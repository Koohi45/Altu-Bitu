#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int compute(int a, int b)
{
	int temp = a;
	vector<int> units;

	while (true) {
		units.push_back(temp % 10);
		temp = (temp * a) % 10;
		if (units[0] == temp)
			break;
	}

	int answer = units[(b - 1) % units.size()];
	if (answer == 0)	return 10;
	return answer;
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
