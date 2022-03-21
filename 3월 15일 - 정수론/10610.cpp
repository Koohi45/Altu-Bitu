#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string thirty(string s) {
	/*
	* 30의 배수려면 10으로 나누어지면서 나누어진 값의 숫자의 합이 3의 배수면 된다.
	* 30의 배수가 있으려면 0이 포함되어야 하며 모든 수의 합이 3의 배수여야 하므로 가장 큰 수는 가장 큰 숫자부터 내림차순으로 구성된 수이다.
	*/

	int sum = 0;

	sort(s.begin(), s.end(), greater<>());	//내림차순으로 sorting
	if (s[s.size() - 1] != '0')	//10으로 나누어져야 함으로 끝자리는 0이어야 함
	{
		return  "-1";
	}

	for (int i = 0; i < s.size(); i++)
		sum += s[i] - '0';

	if (sum % 3 != 0)	//합이 3의 배수가 아니면 30의 배수가 아님
	{
		return "-1";
	}

	return s;
}

int main()
{
	string s;
	cin >> s;

	string ans = thirty(s);
	cout << ans << "\n";
}
