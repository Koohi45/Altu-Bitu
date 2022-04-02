#include <iostream>
#include <vector>

using namespace std;

int stage(vector<pair<int, bool>>& belt, int n, int k)
{
	int cnt = 0, num_of_zero = 0;
	int up = 0, down = n - 1;	//올리는 위치, 내리는 위치
	int size = 2 * n;
	
	while (true) {
		cnt++;

		//벨트 이동
		up = (up - 1 + size) % size;	
		down = (down - 1 + size) % size;


		//로봇 내림
		if (belt[down].second) {
			belt[down].second = false;
		}
		
		//로봇 이동
		for (int i = (down - 1 + size) % size; i != (up - 1 + size) % size; i = (i - 1 + size) % size){
			if (!belt[i].second)	continue;
			
			int next = (i + 1) % size;
			if (!belt[next].second && belt[next].first > 0) {
				belt[next].first--;
				belt[next].second = true;
				belt[i].second = false;
				if (belt[next].first == 0)
					num_of_zero++;
			}
		}

		//이동한 로봇이 내리는 위치에 있을 때 로봇 내림
		if (belt[down].second) {
			belt[down].second = false;
		}

		//로봇 올림
		if (belt[up].first > 0) {
			belt[up].first--;
			belt[up].second = true;
			if (belt[up].first == 0)
				num_of_zero++;
		}

		//단계 종료 조건 확인
		if (num_of_zero >= k)
			break;
	}

	return cnt;
}

int main()
{
	int n, k;
	vector<pair<int, bool>> belt;

	cin >> n >> k;
	belt.assign(2 * n, { 0, false });
	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i].first;
	}

	cout << stage(belt, n, k) << "\n";
}