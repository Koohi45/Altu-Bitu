/*시간초과가 나오는데 어떻게 수정해야할지 감이 안옵니다ㅠㅠ
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int oneAction(int action, queue<bool>& base)
{
	int score = 0;
	if (action == 1) {
		base.push(true);
	}
	else if (action == 2) {
		base.push(true);
		base.push(false);
	}
	else if (action == 3) {
		base.push(true);
		base.push(false);
		base.push(false);
	}
	else {
		base.push(true);
		base.push(false);
		base.push(false);
		base.push(false);
	}
	
	for (int i = 0; i < action; i++) {
		if (base.front())
			score++;
		base.pop();
	}
	return score;
}

int playGame(int n, queue<int> &player, vector<vector<int>> &inning)
{
	int score = 0;
	int cnt_out;	//아웃 카운트
	for (int i = 0; i < n; i++) {
		//한 이닝 시작
		queue<bool> base;	//베이스
		for (int j = 0; j < 3; j++)
			base.push(false);

		cnt_out = 0;	//아웃 카운트 초기화
		while (cnt_out < 3) {
			int player_num = player.front();	//타석에 서 있는 선수
			int action = inning[i][player_num];		//선수의 결과
			if (action == 0) {
				cnt_out++;
			}
			else {
				score += oneAction(action, base);
			}
			player.push(player.front());
			player.pop();
		}
	}
	return score;
}

int maxScore(int n, vector<vector<int>>& inning)
{
	int score = 0;
	int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	
	//순열
	do {
		//타순 결정
		queue<int> player;
		for (int i = 0; i < 3; i++) {
			player.push(arr[i]);
		}
		player.push(1);	//1번 선수 4번 타자로 고정
		for (int i = 3; i < 8; i++) {
			player.push(arr[i]);
		}

		//게임 플레이
		int temp = playGame(n, player, inning);
		score = max(score, temp);
	} while (next_permutation(arr, arr + 8));

	return score;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	vector<vector<int>> inning(n, vector<int> (10, 0));
	for (int i = 0; i < n; i++) 
		for (int j = 1; j < 10; j++)
			cin >> inning[i][j];

	cout << maxScore(n, inning) << '\n';
	return 0;
}
