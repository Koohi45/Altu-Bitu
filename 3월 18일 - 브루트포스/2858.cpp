#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> ci;

ci roomSize(int r, int b)
{
	int size = r + b;
	//갈색 타일이 최소 한 개이므로 바닥의 넓이는 최소 9 이상이다.
	for (int i = 3; i <= sqrt(size); i++) {
		if (size % i != 0)	continue;

		int x = size / i;
		int y = i;

		int red = y * 2 + (x - 2) * 2;
		int brown = size - red;
		
		if (r == red && b == brown) {
			return ci(x, y);
		}
	}
}

int main()
{
	int r, b;
	cin >> r >> b;

	ci answer = roomSize(r, b);
	cout << answer.first << " " << answer.second << "\n";
}