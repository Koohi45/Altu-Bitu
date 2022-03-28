#include <iostream>
#include <vector>

using namespace std;

bool groupWords(string& str)
{
	vector<bool> alphabet(26, false);

	for (int i = 0; i < str.size(); i++) {
		int t = str[i] - 'a';
		if (alphabet[t] == true && str[i] != str[i - 1]) 	//나온 적이 있는데 앞의 문자와 같지 않다면
			return false;
		alphabet[t] = true;	//나왔으면 체크
	}
	return true;
}

int main()
{
	int n;
	string str;
	int answer = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (groupWords(str))	answer++;
	}
	cout << answer << "\n";
}
