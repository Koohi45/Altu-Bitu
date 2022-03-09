#include <iostream>
#include <vector>

using namespace std;

void reverseCard(int a, int b, vector<int>& list)
{
	while (a < b)	//구간을 가리키는 인덱스가 유효할 때까지
	{
		swap(list[a++], list[b--]);	//swap하고 구간을 좁혀가기
	}
}

int main()
{
	int a, b;
	vector<int> arr(20, 0);
	for (int i = 0; i < 20; i++)
		arr[i] = i + 1;

	//입력 및 연산
	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;
		reverseCard(a - 1, b - 1, arr);
	}

	//출력
	for (int i = 0; i < 20; i++)
		cout << arr[i] << " ";
		
}
