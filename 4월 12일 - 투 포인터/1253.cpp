#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGood(vector<int>& num, int n, int idx)
{
	int left = 0, right = n - 1;
	while (left < right) {
		int sum = num[left] + num[right];
		if (left == idx) {
			left++;
			continue;
		}
		if (right == idx) {
			right--;
			continue;
		}

		if (sum == num[idx]) {
			return true;
		}
		else if (sum > num[idx]) {
			right--;
		}
		else {
			left++;
		}
	}
	return false;
}

int numOfGood(int n, vector<int>& num) 
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (isGood(num, n, i))
			ans++;
	}

	return ans;
}

int main()
{
	int n;
	vector<int> num;

	cin >> n;
	num.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end());

	cout << numOfGood(n, num) << '\n';
}