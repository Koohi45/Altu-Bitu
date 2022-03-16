#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

//산술평균
int mean(vector<int>& vec, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += vec[i];

	return round(double(sum) / size);
}

//중앙값
int median(vector<int>& vec, int size)
{
	return vec[size / 2];
}

//최빈값 구하는 함수에 사용하는 비교함수
bool cmp(const pair<int, int> &a, const pair<int, int>& b)
{
	if (a.second != b.second)
		return a.second < b.second;

	return a.first > b.first;
}

//최빈값
int mode(vector<int>& vec, int size)
{
	map<int, int> freq;
	vector<pair<int, int>> freq_vec;
	for (int i = 0; i < size; i++)
		freq[vec[i]]++;

	for (auto iter = freq.begin(); iter != freq.end(); iter++)
	{
		freq_vec.push_back(make_pair(iter->first, iter->second));
	}
	sort(freq_vec.begin(), freq_vec.end(), cmp);

	int last_index = freq_vec.size() - 1;
	if (freq_vec[last_index].second == freq_vec[last_index - 1].second)
		return freq_vec[last_index - 1].first;

	return freq_vec[last_index].first;
}

//범위
int range(vector<int>& vec, int size)
{
	return (vec[size - 1] - vec[0]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> nums;

	cin >> n;
	nums.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());

	cout << mean(nums, n) << "\n";
	cout << median(nums, n) << "\n";
	cout << mode(nums, n) << "\n";
	cout << range(nums, n) << "\n";
}