#include <iostream>
#include <set>

using namespace std;

int main()
{
	int m, num;
	string cmd;
	set<int> s, all;
	
	for (int i = 1; i <= 20; i++)
		all.insert(i);


	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd == "add") {
			cin >> num;
			s.insert(num);
		}
		else if (cmd == "remove") {
			cin >> num;
			s.erase(num);
		}
		else if (cmd == "check") {
			cin >> num;
			if (s.find(num) != s.end())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}
		else if (cmd == "toggle") {
			cin >> num;
			if (s.find(num) != s.end())
				s.erase(num);
			else
				s.insert(num);
		}
		else if (cmd == "all") {
			s = all;
		}
		else if (cmd == "empty") {
			s.clear();
		}
	}

}