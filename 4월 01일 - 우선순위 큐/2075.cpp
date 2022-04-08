#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int nthMax(vector<vector<int>>& v, int n)
{
	priority_queue<int, vector<int>, greater<int>> min_heap;

	//첫번째 줄은 다 힙에 저장
	for (int i = 0; i < n; i++)
		min_heap.push(v[0][i]);

	//힙의 사이즈로 n개를 유지하면서 n번째 값을 갱신
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] > min_heap.top()) {
				min_heap.pop();
				min_heap.push(v[i][j]);
			}
		}
	}

	return min_heap.top();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	vector<vector<int>> v;
	
	cin >> n;
	v.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}


	cout << nthMax(v, n) << '\n';
}