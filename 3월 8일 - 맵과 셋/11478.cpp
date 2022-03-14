#include <iostream>
#include <set>

using namespace std;

int countSubstr(string str)
{
	set<string> substr;

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 1; j <= str.size() - i + 1; j++)
		{
			substr.insert(str.substr(i, j));	//i번 인덱스부터 길이 j의 문자열을 set에 삽입
		}
	}

	return substr.size();
}

int main()
{
	string s;
	cin >> s;
	
	cout << countSubstr(s) << "\n";
}
