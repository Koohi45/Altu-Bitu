#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxHeight(int m, vector<int>& tree)
{
	int size = tree.size();
	int left = 1, right = tree[size - 1];	//절단기 높이로 이분 탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < size; i++) {
			if (tree[i] > mid)	//절단기 높이보다 높은 나무를 자름
				sum += tree[i] - mid;	//얻은 나무 길기 합
		}
		if (sum >= m) {		//합이 m보다 크면 절단기의 높이를 높여야 함
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> tree(n, 0);
	for (int i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree.begin(), tree.end());

	cout << maxHeight(m, tree) << '\n';
	return 0;
}