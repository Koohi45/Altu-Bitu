#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 3e9 + 1;

vector<int> findLiquid(int n, vector<int>& liquid)
{
	vector<int> ans(3);
	long long min_mix = INF;

	for (int i = 0; i < n - 2; i++) {	//제일 왼쪽을 고정
		int left = i + 1, right = n - 1;

		while (left < right) {
			long long mix = (long long)liquid[i] + liquid[left] + liquid[right];
			if (abs(mix) < min_mix) {
				min_mix = abs(mix);
				ans[0] = liquid[i];
				ans[1] = liquid[left];
				ans[2] = liquid[right];
			}
			if (mix == 0)
				return ans;
			if (mix > 0) {
				right--;
			}
			else {
				left++;
			}
		}
	}
	return ans;
}

int main() 
{
	int n;
	vector<int> liquid;
	vector<int> sol;

	cin >> n;
	liquid.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> liquid[i];

	sort(liquid.begin(), liquid.end());
	
	sol = findLiquid(n, liquid);
	for (int i = 0; i < 3; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}
