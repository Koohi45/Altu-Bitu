#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vec;

//0 <-> 1
void operate(vec& a, int row, int col)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a[row + i][col + j] = a[row + i][col + j] == 1 ? 0 : 1;
		}
	}
}

int minCount(vec& a, vec& b, int n, int m)
{
	int count = 0;
	
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				operate(a, i, j);
				count++;
			}
		}
	}

	//전체 검사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j])
				return -1;
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	char c;

	cin >> n >> m;
	vec mat_a(n, vector<int>(m, 0));
	vec mat_b(n, vector<int>(m, 0));

	//행렬A 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			mat_a[i][j] = c - '0';
		}
	}
	//행렬B 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			mat_b[i][j] = c - '0';
		}
	}

	cout << minCount(mat_a, mat_b, n, m) << '\n';
}