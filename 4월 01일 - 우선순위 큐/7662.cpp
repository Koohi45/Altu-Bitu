#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

priority_queue<ci> max_heap;
priority_queue<ci, vector<ci>, greater<ci>> min_heap;
vector<bool> check;	//각 heap에 들어가 있는 숫자가 유효한지 체크할 배열

//초기화
void init()
{
	while (!max_heap.empty())
		max_heap.pop();
	while (!min_heap.empty())
		min_heap.pop();
}

//연산자가 I일 때
void push(int n, int i)
{
	max_heap.push({ n, i });
	min_heap.push({ n, i });
	check[i] = true;
}

//연산자가 D일 때
void pop(int n)
{
	//가장 상위에 있는 값이 유효하지 않으면 pop
	while (!max_heap.empty() && !check[max_heap.top().second])
		max_heap.pop();

	while (!min_heap.empty() && !check[min_heap.top().second])
		min_heap.pop();

	if (n == 1 && !max_heap.empty())
	{
		auto t = max_heap.top();
		check[t.second] = false;
		max_heap.pop();	
	}
	else if(n == -1 && !min_heap.empty())
	{
		auto t = min_heap.top();
		check[t.second] = false;
		min_heap.pop();
	}
}

void findMaxMin(vector<pair<char, int>>& vec, int k)
{
	init();
	check.assign(k, false);

	for (int i = 0; i < k; i++) {
		char op = vec[i].first;
		int n = vec[i].second;
		if (op == 'I') {
			push(n, i);
		}
		else {
			pop(n);
		}
	}

	//최댓값이 유효할 때까지 pop
	while (!max_heap.empty() && !check[max_heap.top().second]) {
		max_heap.pop();
	}

	//최솟값이 유효할 때까지 pop
	while (!min_heap.empty() && !check[min_heap.top().second]) {
		min_heap.pop();
	}

	if (max_heap.empty()) {
		cout << "EMPTY\n";
		return;
	}

	cout << max_heap.top().first << " " << min_heap.top().first << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k, n;
	char op;

	vector<pair<char, int>> vec;

	cin >> t;
	while (t--) {
		cin >> k;
		vec.clear();
		for (int i = 0; i < k; i++) {
			cin >> op >> n;
			vec.push_back({ op, n });
		}

		findMaxMin(vec, k);
	}
}