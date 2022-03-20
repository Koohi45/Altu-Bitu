#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1e6;

//MAX까지 소수 찾아서 반환
vector<bool> findAllPrime() {
	vector<bool> is_prime(MAX + 1, true);

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= MAX; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

string conjecture(int n, vector<bool>& p)
{
	string ans = to_string(n) + " = ";
	for (int i = 3; i < n; i++)
	{
		int j = n - i;
		if (p[i] && p[j])
		{
			ans += to_string(i) + " + " + to_string(j);
			return ans;
		}		
	}

	return  "Goldbach's conjecture is wrong.";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	
	auto prime = findAllPrime();

	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << conjecture(n, prime) << "\n";
	}
}