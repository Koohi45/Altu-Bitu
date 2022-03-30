#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> &vec, int start, int end, int key)
{
	while (end >= start)
	{
		int mid = (start + end) / 2;
		if (vec[mid] == key)
			return true;
		else if (vec[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return false;
}

void testMemory()
{
	int n, m, temp;
	vector<int> word;

	cin >> n;
	while (n--)
	{
		cin >> temp;
		word.push_back(temp);
	}
	sort(word.begin(), word.end());

	cin >> m;
	while (m--) 
	{
		cin >> temp;
		if (binarySearch(word, 0, word.size() - 1, temp))
			cout << "1\n";
		else
			cout << "0\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;
	while (t--)
		testMemory();
}
