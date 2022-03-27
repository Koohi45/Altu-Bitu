#include <iostream>
#include <map>

using namespace std;

void attCheck(string start, string end, string streaming)
{
	int ans = 0;
	string time, name;
	map<string, pair<int, int>> check;	//value값 중 처음 수는 입장, 다음 수는 퇴장
	
	while (cin >> time >> name)
	{
		if (time <= start)
			check[name].first++;
		else if (time >= end && time <= streaming)
			check[name].second++;
	}

	for (auto iter = check.begin(); iter != check.end(); iter++)
	{
		if (iter->second.first > 0 && iter->second.second)
			ans++;
	}

	cout << ans << "\n";
}

int main()
{
	string s, e, q;
	//freopen("input.txt", "r", stdin);
	cin >> s >> e >> q;
	attCheck(s, e, q);
}