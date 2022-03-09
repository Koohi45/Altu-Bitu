#include <iostream>

using namespace std;

const int DAY_SEC = 24 * 60 * 60;

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
		cout << (temp_time) / 3600 << " " << (temp_time / 60) % 60 << " " << (temp_time) % 60 << "\n";
	}
	*time = temp_time;
}

int main()
{
	int hour, min, sec;	//현재 시간
	int q;				//쿼리 개수
	int t;

	//입력
	cin >> hour >> min >> sec;
	cin >> q;

	int now = hour * 3600 + min * 60 + sec;

	for (int i = 0; i < q; i++)
	{
		cin >> t;
		clock(t, &now);
	}

	
}
