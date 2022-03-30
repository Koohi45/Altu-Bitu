#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<vector<bool>> row(9, vector<bool>(10, false));
vector<vector<bool>> col(9, vector<bool>(10, false));
vector<vector<bool>> rec(9, vector<bool>(10, false));
vector<pair<int, int>> blank_coord;

int findArea(int row, int col) {
	return 3 * (row / 3) + (col / 3);
}

bool backtracking(int cnt, int size)
{
	if (cnt == size)	return true;
	int r = blank_coord[cnt].first;
	int c = blank_coord[cnt].second;
	int a = findArea(r, c);
	for (int i = 1; i < 10; i++) {
		if (!row[r][i] && !col[c][i] && !rec[a][i]) {
			row[r][i] = true;
			col[c][i] = true;
			rec[a][i] = true;
			sudoku[r][c] = i;
			if (backtracking(cnt + 1, size)) return true;
			else {
				row[r][i] = false;
				col[c][i] = false;
				rec[a][i] = false;
			}
		}
	}
	return false;
}

void completeSudoku()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0)	blank_coord.push_back({ i, j });
			else {
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				rec[findArea(i, j)][sudoku[i][j]] = true;
			}
		}
	}

	backtracking(0, blank_coord.size());
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}

	completeSudoku();
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
}