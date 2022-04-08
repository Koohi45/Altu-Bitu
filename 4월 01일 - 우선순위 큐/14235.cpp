#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, a, v;

	priority_queue<int> present;

	cin >> n;
	while (n--) {
		cin >> a;
		if (a == 0) {
			if (!present.empty()) {
				cout << present.top() << '\n';
				present.pop();
			}
			else
				cout << -1 << '\n';
		}
		else {
			while (a--) {
				cin >> v;
				present.push(v);
			}
		}
	}
}