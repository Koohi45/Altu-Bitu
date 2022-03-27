#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

bool cmp(ci &a, ci &b)
{
	if (a.second != b.second)
		return a.second < b.second;
	if (a.first != b.first)
		return a.first < b.first;
}

void sortPoint(int n)
{
	int x, y;
	vector<ci> point;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}

	sort(point.begin(), point.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << point[i].first << " " << point[i].second << "\n";
}

int main()
{
	int n;	//점의 개수

	cin >> n;

	sortPoint(n);
}
