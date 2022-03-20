#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

string red(string& str)
{
	int idx = str.find(':');
	int n = stoi(str.substr(0, idx));
	int m = stoi(str.substr(idx + 1));

	int g = gcd(max(n, m), min(n, m));
	n /= g;
	m /= g;

	return to_string(n) + ":" + to_string(m);
}

int main()
{
	string s;
	cin >> s;

	cout << red(s) << "\n";
}