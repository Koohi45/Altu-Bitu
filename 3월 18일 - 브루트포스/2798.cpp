#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int newBlackJack(int n, int m, vector<int>& card)
{
	int answer = 0;

	vector<bool> comb(n, false);	// 3개 숫자 조합
	for (int i = 0; i < 3; i++) {
		comb[i] = true;
	}

	do {
		int temp = 0;
		for (int i = 0; i < n; i++) {	//3개 숫자 합
			if (comb[i]) {
				temp += card[i];
			}
		}
		
		if (temp > answer && temp <= m)
			answer = temp;
	} while (prev_permutation(comb.begin(), comb.end()));

	return answer;
}

int main()
{
	int n, m;
	vector<int> card;

	cin >> n >> m;
	card.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> card[i];

	cout << newBlackJack(n, m, card) << "\n";
}