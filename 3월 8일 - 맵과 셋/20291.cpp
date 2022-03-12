#include <iostream>
#include <map>

using namespace std;

void filenameExt(int n)
{
	string filename;
	map<string, int> ext;

	for (int i = 0; i < n; i++)
	{
		cin >> filename;
		int pos = filename.find(".");	
		ext[filename.substr(pos + 1)]++;	//.뒤에 문자열을 키로 value 값을 하나 증가
	}

	for (auto iter = ext.begin(); iter != ext.end(); iter++)
	{
		cout << iter->first << " " << iter->second << "\n";
	}
}

int main()
{
	int n;
	cin >> n;

	filenameExt(n);
}
