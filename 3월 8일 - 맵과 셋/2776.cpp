/*
* 같은 코드인데 백준에서는 시간초과가 나기도하고 안나기도 하고 그럽니다...
* 코드를 다르게 수정하는 것이 좋을까요?
*/


#include <iostream>
#include <map>

using namespace std;

void testMemory()
{
	int n, m, temp;
	map<int, int> note;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		note[temp] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (note[temp] == 1)
			cout << "1\n";
		else
			cout << "0\n";
		/*
		* 튜터링 자료에서 46 슬라이드 마무리 부분에 주어진 코드를 실행했을 때
		* 0이 나오던데 이 부분을 그냥
		* cout << note[temp] << "\n";
		* 로 해도 괜찮은가요?
		*/
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;

	cin >> t;
	while (t--)
		testMemory();
}
