/*
* 예시 입력을 넣었을 시 예시 출력이 나오는데 
* 제출하면 틀렸다고 하더라구요...
* 어디가 틀렸는지 고민해봐도 잘 모르겠어서
* 여쭤보고 싶습니다...
*/
#include <iostream>
#include <vector>

using namespace std;

int resorting(int n, vector<int>& a, vector<int> b)
{
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b[i] < b[j] && a[i] < a[j])			//b의 원소 값과 a의 원소 값을 비교
				swap(a[i], a[j]);					//b[i]의 값이 더 크면 곱해지는 a[i]값이 더 작아야함
			else if (b[i] > b[j] && a[i] > a[j])
				swap(a[i], a[j]);
		}
	}

	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];

	return ans;
}

int main()
{
	int n;
	vector<int> a, b;

	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];


	cout << resorting(n, a, b) << "\n";
}