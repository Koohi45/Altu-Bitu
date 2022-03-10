#include <iostream>

using namespace std;

const int DAY_SEC = 86400;
const int HOUR_SEC = 3600;
const int MIN_SEC = 60;

void clock(int query, int* time)
{
	int c;
	int temp_time = *time;

	if (query == 1)
	{
		cin >> c;
		temp_time += c;
		temp_time %= DAY_SEC;
	}
	else if (query == 2)
	{
		cin >> c;
		temp_time -= c;
		while (temp_time < 0)
			temp_time += DAY_SEC;
	}
	else if (query == 3)
	{
		cout << (temp_time) / HOUR_SEC << " " << (temp_time / MIN_SEC) % MIN_SEC << " " << (temp_time) % MIN_SEC << "\n";
	}
	*time = temp_time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int hour, min, sec;	//현재 시간
	int q;				//쿼리 개수
	int t;

	//입력
	cin >> hour >> min >> sec;
	cin >> q;

	int now = hour * HOUR_SEC + min * MIN_SEC + sec;

	for (int i = 0; i < q; i++)
	{
		cin >> t;
		clock(t, &now);
	}

	
}
