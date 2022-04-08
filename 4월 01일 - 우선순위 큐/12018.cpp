#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxNumOfCourse(vector<pair<int, int>>& sugang, vector<priority_queue<int>>& mile, int n, int m)
{
	int answer = 0;
	vector<int> use_mileage(n, 0);	//수강한다면 사용될 마일리지 저장

	for (int i = 0; i < n; i++) {
		//신청한 사람 수가 수강인원보다 적을 때
		if (sugang[i].first < sugang[i].second) {
			use_mileage[i] = 1;
			continue;
		}

		//(수강인원 수)번째 사람의 마일리지까지 pop
		for (int j = 0; j < sugang[i].second - 1; j++)
			mile[i].pop();
		use_mileage[i] = mile[i].top();
	}

	sort(use_mileage.begin(), use_mileage.end());	//오름차순 정렬
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + use_mileage[i] <= m) {	//마일리지를 초과하지 않을 때까지 수강신청
			sum += use_mileage[i];
			answer++;
		}
	}

	return answer;
}

int main()
{
	int n, m;
	int each_m;

	cin >> n >> m;
	vector<pair<int, int>> num_sugang(n);	//신청한 사람과 수강인원을 저장
	vector<priority_queue<int>> mileage(n);	//각 과목의 신청한 사람 마일리지
	for(int i = 0; i < n; i++) {
		cin >> num_sugang[i].first >> num_sugang[i].second;
		for (int j = 0; j < num_sugang[i].first; j++) {
			cin >> each_m;
			mileage[i].push(each_m);
		}
	}

	cout << maxNumOfCourse(num_sugang, mileage, n, m) << '\n';
}