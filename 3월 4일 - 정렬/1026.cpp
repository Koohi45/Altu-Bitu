#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int resorting(int n)
{
	vector<int> a(n, 0), b(n, 0);
	int ans = 0;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];

	return ans;
}

int main()
{
	int n;
	cin >> n;
	
	cout << resorting(n) << "\n";
}