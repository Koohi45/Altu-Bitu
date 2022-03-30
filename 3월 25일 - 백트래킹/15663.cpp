#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> num(8);
vector<int> arr(8);
vector<bool> check(9);

void backtracking(int cnt)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int use_num = 0;	//이전 사용된 숫자
	for (int i = 0; i < n; i++) {
		if (!check[i] && num[i] != use_num) {
			arr[cnt] = use_num = num[i];
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.begin() + n);
	backtracking(0);
}