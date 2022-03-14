#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> ci;

bool cmp(const ci &a, const ci &b)
{
	if (a.second != b.second)
		return a.second > b.second;

	if (a.first.size() != b.first.size())
		return a.first.size() > b.first.size();

	return a < b;
}

void voca(int n, int m)
{
	string str;
	map<string, int> map_word;
	vector<ci> vec_word;

	while (n--)
	{
		cin >> str;
		if (str.size() >= m)
		{
			map_word[str]++;
		}
	}

	//vector로 복사해서 정렬
	for (auto iter = map_word.begin(); iter != map_word.end(); iter++)
	{
		vec_word.push_back(make_pair(iter->first, iter->second));	
	}

	sort(vec_word.begin(), vec_word.end(), cmp);

	for (int i = 0; i < vec_word.size(); i++)
		cout << vec_word[i].first << "\n";
}

int main()
{
	int n, m;
	cin >> n >> m;

	voca(n, m);
}
