/*더 간단한 방법이 있을까요?
* 현재 작성한 코드가 너무 복잡한 것 같습니다...
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef pair<int, int> ci;
vector<int> num(1000, 0);	// 각 질문 숫자마다 가능한 숫자를 체크할 배열

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

//차례대로 숫자와 질문한 숫자의 스트라이크, 볼을 계산하고 입력된 스트라이크, 볼과 같은지 확인하는 함수
void calStrikeBall(string s, int strike, int ball) 
{
	int temp_strike, temp_ball;
	for (int i = 123; i < 1000; i++) {
		string temp = to_string(i);

		temp_strike = 0;
		temp_ball = 0;

		if (!valid(temp))	//숫자가 조건에 유효한지 확인
			continue;

		for (int j = 0; j < 3; j++) {
			if (temp[j] == s[j])	//스트라이크인 숫자가 있으면
				temp_strike++;		//현재 스트라이크 수를 하나 증가
			else if (s.find(temp[j]) != s.npos)	//temp의 숫자가 s에는 있지만 자리가 같지 않은 경우
				temp_ball++;					//볼 수를 하나 증가
		}
		if (temp_strike == strike && temp_ball == ball) {	//계산한 스트라이크와 볼이 입력된 값과 같으면 해당 숫자 배열 값을 증가
			num[i]++;
		}
	}
}

int baseball(map<string, ci> &m)
{
	int cnt = 0;
	int max = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		calStrikeBall(iter->first, iter->second.first, iter->second.second);
	}

	//배열 중 가장 큰 값을 가진 숫자가 가능한 숫자이고 최대값을 가진 숫자를 세서 반환
	for (int i = 123; i < 1000; i++) {
		if (num[i] > max) {
			max = num[i];
			cnt = 1;
		}
		else if (num[i] == max) {
			cnt++;
		}
	}
	return cnt;
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
