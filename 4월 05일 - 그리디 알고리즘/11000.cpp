#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int countRoom(vector<ci>& lecture, int n)
{
	priority_queue<int, vector<int>, greater<int>> min_heap;	//현재 시점에 각 강의실의 끝나는 시간을 저장
	min_heap.push(lecture[0].second);
	for (int i = 1; i < n; i++) {
		int start = lecture[i].first;
		int end = lecture[i].second;

		if (min_heap.top() <= start) {
			min_heap.pop();
		}
		
		min_heap.push(end);
	}
	
	return min_heap.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<ci> lecture(n, { 0, 0 });
	for (int i = 0; i < n; i++) {
		cin >> lecture[i].first >> lecture[i].second;
	}

	sort(lecture.begin(), lecture.end());
	cout << countRoom(lecture, n) << '\n';
}