#include <iostream>
#include <deque>

using namespace std;

string findPassword(string& str)
{
	deque<char> prev_cursor;
	deque<char> next_cursor;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			if (prev_cursor.empty())
				continue;
			next_cursor.push_front(prev_cursor.back());
			prev_cursor.pop_back();
		}
		else if (str[i] == '>') {
			if (next_cursor.empty())
				continue;
			prev_cursor.push_back(next_cursor.front());
			next_cursor.pop_front();
		}
		else if (str[i] == '-') {
			if (prev_cursor.empty())
				continue;
			prev_cursor.pop_back();
		}
		else {
			prev_cursor.push_back(str[i]);
		}
	}

	string answer = "";
	while (!prev_cursor.empty()) {
		answer += prev_cursor.front();
		prev_cursor.pop_front();
	}
	while (!next_cursor.empty()) {
		answer += next_cursor.front();
		next_cursor.pop_front();
	}

	return answer;
}

int main()
{
	int t;
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		cout << findPassword(str) << '\n';
	}
}