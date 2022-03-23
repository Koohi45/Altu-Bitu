#include <iostream>
#include <string>

using namespace std;

string bigNumberSum(string a, string b) {
	string answer = "";

	int temp = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;

	while (i >= 0 && j >= 0) {
		temp = (a[i] - '0') + (b[j] - '0') + temp;
		answer = to_string(temp % 10) + answer;
		temp /= 10;
		i--; j--;
	}

	//a가 더 길 때 남은 앞의 수 처리
	while (i >= 0) {
		temp = (a[i] - '0') + temp;
		answer = to_string(temp % 10) + answer;
		temp /= 10;
		i--;
	}

	//b가 더 길 때 남은 앞의 수 처리
	while (j >= 0) {
		temp = (b[j] - '0') + temp;
		answer = to_string(temp % 10) + answer;
		temp /= 10;
		j--;
	}

	//제일 앞자리 덧셈의 결과가 두자리 수일 때 십의 자리 추가
	if (temp)
		answer = to_string(temp) + answer;

	return answer;
}


int main() {
	string a, b;
	cin >> a >> b;

	string ans = bigNumberSum(a, b);
	cout << ans << "\n";
}
