#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numOfGood(int n, vector<int>& num) 
{
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int left = 0, right = n - 1;

		while (left < right) {
			int sum = num[left] + num[right];
			if (left == i) {
				left++;
				continue;
			}
			if (right == i) {
				right--;
				continue;
			}

			if (sum == num[i]) {
				ans++;
				break;
			}
			else if (sum > num[i]) {
				right--;
			}
			else {
				left++;
			}
		}
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