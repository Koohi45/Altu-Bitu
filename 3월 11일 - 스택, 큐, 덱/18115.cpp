#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void findInitCard(vector<int>& vec, deque<int>& deq, int size)
{
	for (int i = 1; i <= size; i++)
	{
		int x = vec[size - i];
		if (x == 1)
		{
			//맨 앞에 삽입
			deq.push_front(i);
		}
		else if (x == 2)
		{
			//맨 앞에 있는 거 빼놓고 i숫자 카드를 앞에 넣은 다음 다시 앞에 삽입
			int temp = deq.front();
			deq.pop_front();
			deq.push_front(i);
			deq.push_front(temp);
		}
		else
		{
			//맨 뒤에 삽입
			deq.push_back(i);
		}
	}
}

int main()
{
	int n;
	vector<int> seq;
	deque<int> card;
	
	cin >> n;
	seq.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> seq[i];

	findInitCard(seq, card, n);
	while(!card.empty())
	{
		cout << card.front() << " ";
		card.pop_front();
	}
	cout << "\n";
}