/*백준에서 틀렸다고 하는데 어떻게 수정해야할지 잘 모르겠습니다ㅠㅠ
*/

#include <iostream>

using namespace std;

int fourSquares(int n) {
	int j, k;
	int ans = 4;
	for (int i = sqrt(n); i > 0; i--) {
		int temp = 0;
		
		//첫번째
		if (i * i == n) {
			temp = 1;
			ans = min(ans, temp);
		}
			
		
		//두번째
		j = n - i * i;
		k = sqrt(j);
		if (j > 0 && k * k == j) {
			temp = 2;
			ans = min(ans, temp);
		}
			
		
		//세번째
		j = j - k * k;
		k = sqrt(j);
		if (j > 0 && k * k == j){
			temp = 3;
			ans = min(ans, temp);
		}

		//네번째
		j = j - k * k;
		k = sqrt(j);
		if (j > 0 && k * k == j){
			temp = 4;
			ans = min(ans, temp);
		}

	}
	return ans;
}

int main()
{
	int n;
	cin >> n;

	cout << fourSquares(n) << "\n";
}