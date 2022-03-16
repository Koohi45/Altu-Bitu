#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string palindrome(string n)
{
	string pal;
	string odd;
	vector<int> alphabet(26, 0);	
	for (int i = 0; i < n.size(); i++)
	{
		int a = n[i] - 'A';
		alphabet[a]++;		//대문자가 몇 개인지 저장
	}

	int check = 0;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] % 2 == 1)	//홀수개인 대문자가 몇개인지 확인
		{
			check++;
			odd = i + 'A';	//1개일 때 사용할 홀수 개인 알파벳 저장
		}
	}
	
	if (check > 1)	//2개 이상이면 팰린드롬을 만들 수 없음
	{
		return "I'm Sorry Hansoo";
	}

	for (int i = 0; i < 26; i++)
	{
		int count = alphabet[i] / 2;	//알파벳 순서대로 개수의 반만큼 가져와서 붙여줌
		while (count--)
			pal += (i + 'A');
	}
	string reverse_pal = pal;
	reverse(reverse_pal.begin(), reverse_pal.end());	//팰린드롬의 앞부분을 그대로 뒤집은 문자열 생성
	pal = pal + odd + reverse_pal;	//홀수개인 알파벳과 뒤집은 문자열 붙임

	return pal;
}

int main()
{
	string name;
	cin >> name;

	cout << palindrome(name) << "\n";
}