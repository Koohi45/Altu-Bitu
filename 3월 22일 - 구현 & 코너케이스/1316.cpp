#include <iostream>
#include <vector>

using namespace std;

int groupWords(vector<string>& word)
{
	int answer = 0;
	bool flag;
	vector<int> alphabet;

	for (int i = 0; i < word.size(); i++) {
		alphabet.assign(26, 0);
		flag = true;
		for (int j = 0; j < word[i].size(); j++) {
			int t = word[i][j] - 'a';
			if (alphabet[t] != 0 && alphabet[t] != j) {	//한번도 나온 적이 없거나 연속으로 나오지 않고 뒤에 또 나올 때
				flag = false;
				break;
			}
			else
				alphabet[t] = j + 1;	//숫자가 연속으로 나오는 중이라면 마지막 문자의 인덱스 + 1을 해당 알파벳 배열에 저장
		}
		if (flag)
			answer++;
	}

	return answer;
}

int main()
{
	int n;
	string s;
	vector<string> word;

	cin >> n;
	word.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> word[i];
	cout << groupWords(word) << "\n";
}