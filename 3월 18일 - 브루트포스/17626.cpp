#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int fourSquares(int n) {
	vector<int> vec(n + 1, 0);

	for (int i = 1; i * i <= n; i++)
		vec[i * i] = 1;	//제곱수는 1로 저장

	for (int i = 2; i <= n; i++) {
		if (vec[i] == 0) {	//제곱수가 아닌 경우는 j*j 와 (i - j*j)개의 1*1의 합으로 생각하여 초기화
			int j = sqrt(i);
			vec[i] = 1 + (i - j * j);	//i = j*j + 1*1 + 1*1 + ... 
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j < i; j++) {
			int temp = vec[j * j] + vec[i - j * j];
			vec[i] = min(vec[i], temp);
		}
	}

	return vec[n];
}

int main()
{
	int n;
	cin >> n;

	cout << fourSquares(n) << "\n";
}