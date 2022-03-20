#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void thirty(vector<int>& arr)
{
	/*
	* 30의 배수려면 10으로 나누어지면서 나누어진 값의 숫자의 합이 3의 배수면 된다.
	* 30의 배수가 있으려면 0이 포함되어야 하며 모든 수의 합이 3의 배수여야 하므로 가장 큰 수는 가장 큰 숫자부터 내림차순으로 구성된 수이다.
	*/
	int sum = 0;

	sort(arr.begin(), arr.end(), greater<>());	//내림차순으로 sorting
	if (arr[arr.size() - 1] != 0)	//10으로 나누어져야 함으로 끝자리는 0이어야 함
	{
		cout << -1 << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];

	if (sum % 3 != 0)	//합이 3의 배수가 아니면 30의 배수가 아님
	{
		cout << -1 << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
	cout << "\n";
}

int main()
{
	string s;
	vector<int> arr;
	
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		arr.push_back(s[i] - '0');

	thirty(arr);
}