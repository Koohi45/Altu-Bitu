/* (질문)
* 따로 실행해보면 백준 예시 출력이랑 같게 나오는데
* 백준에서는 틀리다고 합니다. 그 이유를 고민해도 잘 모르겠어서
* 여쭤보고 싶습니다!
*/
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	
	return gcd(y, x % y);
}

pair<int, int> gcdLcm(int n, int m)
{
	int a = 0, b = 0;
	int min = n + m;
	int temp;
	for (int i = 2; n * i <= m / i; i++)
	{
		if (m % i == 0 && (gcd(m / i, n * i) == n))
		{
			temp = n * i + m / i;
			if (min > temp)
			{
				min = temp;
				a = n * i;
				b = m / i;
			}
		}	
	}

	return make_pair(a, b);
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	auto answer = gcdLcm(n, m);
	cout << answer.first << ' ' << answer.second << '\n';
}