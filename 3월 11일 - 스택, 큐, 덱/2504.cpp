#include <iostream>
#include <stack>
#include <map>

using namespace std;

int sol(string &str)
{
	/* (()[[]])([]) 의 연산은
	* 2*(2 + 3 *3) + 2*3
	* = 2*2 + 2*3*3 + 2*3
	* 으로 (())([[]])([])처럼 분배법칙한 것과 같음
	*/
	stack<char> st;
	map<char, char> m;
	int sum = 0;
	int mult = 1;

	m[']'] = '[';
	m[')'] = '(';

	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
			case '(':
				mult *= 2;
				st.push(str[i]);
				break;
			case '[':
				mult *= 3;
				st.push(str[i]);
				break;
			case ')':
			case ']':
				if (st.empty() || st.top() != m[str[i]])
					return 0;
				if(str[i - 1] == m[str[i]])
					sum += mult;
				st.pop();
				if (str[i] == ')')
					mult /= 2;
				else if (str[i] == ']')
					mult /= 3;
				break;					
		}
	}

	if (!st.empty())
		return 0;

	return sum;

}

int main()
{
	string s;
	
	cin >> s;
	cout << sol(s) << "\n";
}