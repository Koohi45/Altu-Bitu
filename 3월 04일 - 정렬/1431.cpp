#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string str)
{
	int res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))	//문자가 숫자이면
		{
			res += (str[i] - '0');	//해당 숫자를 합함
		}
	}

	return res;
}

bool cmp(const string& a, const string& b)
{
	if (a.size() != b.size())	
		return a.size() < b.size();

	if (sum(a) != sum(b))
		return sum(a) < sum(b);

	return a < b;
}

int main()
{
	int n;
	vector<string> serial_num;

	cin >> n;
	serial_num.assign(n, "");
	for(int i = 0; i < n; i++)
		cin >> serial_num[i];
	
	sort(serial_num.begin(), serial_num.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << serial_num[i] << "\n";
}
