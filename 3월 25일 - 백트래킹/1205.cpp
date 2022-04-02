#include <iostream>
#include <vector>

using namespace std;

int myRank(vector<int>& rank, int n, int new_score)
{
	if (n == 0)	//랭킹 리스트에 올라와 있는 점수가 없는 경우
		return 1;

	if (new_score <= rank[rank.size() - 1])	//랭킹 리스트에 올라갈 수 없는 점수인 경우
		return -1;

	for (int i = 1; i <= n; i++) {
		if (new_score >= rank[i])
			return i;
		
		if (new_score < rank[i] && new_score > rank[i + 1])
			return i + 1;
	}
}

int main()
{
	int n, new_score, list_num;
	vector<int> rank;

	cin >> n >> new_score >> list_num;
	rank.assign(list_num + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> rank[i];
	
	cout << myRank(rank, n, new_score) << "\n";

}