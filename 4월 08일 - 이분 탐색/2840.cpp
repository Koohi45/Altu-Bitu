#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, char> ci;

string findLuckyWheel(int n, int k, vector<ci>& rot_alphabet)
{
	string ans = "";
	vector<char> lucky(n, '?');	//행운의 바퀴 '?'로 초기화
	int arrow = 0;	//화살표가 가리킬 idx
	for (int i = 0; i < k; i++) {
		int rot = rot_alphabet[i].first % n;
		char al = rot_alphabet[i].second;
		auto iter = find(lucky.begin(), lucky.end(), al);

		arrow = (arrow - rot + n) % n; //회전
		if (lucky[arrow] == al && arrow == iter - lucky.begin())	//같은 칸에 같은 알파벳
			continue;
		else if (lucky[arrow] == '?' && iter == lucky.end())	//중복되지 않으면서 칸이 결정되어 있지 않을 떄
			lucky[arrow] = al;
		else return "!";
	}
	
	int cnt = n;
	while (cnt--) {
		ans += lucky[arrow++];
		arrow %= n;
	}
	return ans;
}

int main()
{
	int n, k;

	cin >> n >> k;
	vector<ci> rot_alphabet(k);
	for (int i = 0; i < k; i++){
		cin >> rot_alphabet[i].first >> rot_alphabet[i].second;
	}

	cout << findLuckyWheel(n, k, rot_alphabet) << '\n';
}