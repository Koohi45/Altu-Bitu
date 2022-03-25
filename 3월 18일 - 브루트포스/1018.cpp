#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

//맨 위 칸의 위치가 [row][col]일 때 다시 색칠할 칸 개수 구하기
int numberOfChange(int row, int col)
{
	int cntB = 0, cntW = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//검사하는 8x8 범위의 맨 위 칸이 검정일 때
			if (((i + j) % 2 == 0 && board[row + i][col + j] != 'B') || ((i + j) % 2 == 1 && board[row + i][col + j] != 'W'))
				cntB++;
		}
	}
	//검사하는 8x8범위의 맨 위 칸이 흰색일 때
	cntW = 64 - cntB;
	return min(cntB, cntW);
}

int minChangeColor(int n, int m)
{
	int minimum = 32; 
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int temp = numberOfChange(i, j);
			minimum = min(minimum, temp);
		}
	}
	return minimum;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	board.assign(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	cout << minChangeColor(n, m) << "\n";
}