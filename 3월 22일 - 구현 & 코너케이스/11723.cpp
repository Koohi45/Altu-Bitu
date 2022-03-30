#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, num;
	string cmd;
	vector<bool> check(21, false);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == "all") {
			for (int j = 1; j <= 20; j++)
				check[j] = true;
			continue;
		}
		else if (cmd == "empty") {
			for (int j = 1; j <= 20; j++)
				check[j] = false;
			continue;
		}

		cin >> num;
		if (cmd == "add") {
			check[num] = true;
		}
		else if (cmd == "remove") {
			check[num] = false;
		}
		else if (cmd == "check") {
			if (check[num])
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (cmd == "toggle") {
			if (check[num])
				check[num] = false;
			else
				check[num] = true;
		}
	}
}
