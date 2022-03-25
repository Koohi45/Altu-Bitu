#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef pair<int, int> ci;

//숫자에 0이 들어가거나 같은 숫자가 있는지 확인하는 함수
bool valid(string str) {
	bool result = true;

	if (str.find('0') != str.npos) {
		result = false;
		return result;
	}


	if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2])
		result = false;

	return result;
}

//a와 b의 스트라이크, 볼 계산
ci calStrikeBall(string a, string b)
{
	int strike = 0, ball = 0;
	for (int i = 0; i < 3; i++) {
		if (a[i] == b[i])	//스트라이크인 숫자가 있으면
			strike++;		//현재 스트라이크 수를 하나 증가
		else if (a.find(b[i]) != a.npos)	//b의 숫자가 a에는 있지만 자리가 같지 않은 경우
			ball++;							//볼 수를 하나 증가
	}
	return ci(strike, ball);
}

int baseball(map<string, ci>& m)
{
	int answer = 0;
	int cnt;
	for (int i = 123; i < 1000; i++) {
		string temp = to_string(i);
		cnt = 0;

		if (!valid(temp))
			continue;

		for (auto iter = m.begin(); iter != m.end(); iter++) {
			string que_str = iter->first;
			int strike = iter->second.first;
			int ball = iter->second.second;

			ci result = calStrikeBall(temp, que_str);
			if (strike == result.first && ball == result.second)
				cnt++;
		}
		if (cnt == m.size())
			answer++;
	}

	return answer;
}


int main()
{
	int n;
	string s;
	int strike, ball;
	map<string, ci> question_num;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> strike >> ball;
		question_num[s] = ci(strike, ball);
	}

	cout << baseball(question_num) << "\n";
}
