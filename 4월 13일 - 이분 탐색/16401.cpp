/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntNum(int len, vector<int>& snack)
{
	int cnt = 0;
	for (int i = 0; i < snack.size(); i++)
		cnt += (snack[i] / len);	//과자를 len으로 했을 때 줄 수 있는 조카의 수

	return cnt;
}

int maxLength(int left, int right, int target, vector<int>& snack)
{
	while (left <= right) {
		//과자 길이가 mid일 때 m명의 조카에게 과자를 줄 수 있는가
		int mid = (left + right) / 2;
		int max_num = cntNum(mid, snack);

		if (max_num >= target) {	//max_num이 target보다 크다면 과자 길이를 늘이기
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left - 1;
}

int main()
{
	int n, m;

	//입력
	cin >> m >> n;
	vector<int> snack(n, 0);
	for (int i = 0; i < n; i++)
		cin >> snack[i];
	
	//정렬
	sort(snack.begin(), snack.end());

	//연산 & 출력
	cout << maxLength(1, snack[n - 1], m, snack) << '\n';
	return 0;
}
*/