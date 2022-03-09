#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxRecruit(int n)
{
	int doc_score, int_score;	//서류심사, 면접시험 성적
	int max_num = 1;			//선발 가능한 최대 신입사원 수
	int com_score;				//비교할 가장 높은 점수
	vector<pair<int, int>> score(n);	//성적 저장 배열

	for (int i = 0; i < n; i++)
	{
		cin >> doc_score >> int_score;
		score[i] = make_pair(doc_score, int_score);
	}

	sort(score.begin(), score.end());	//서류심사 성적을 기준으로 정렬
	com_score = score[0].second;

	for (int i = 1; i < n; i++)			//정렬된 배열에서 순서대로 자기 앞에서 나온 최고 순위와 비교
	{
		if (score[i].second < com_score)	//해당 지원자가 앞 순서 지원자들에서의 최고 면접성적보다 높다면	
		{
			max_num++;						//최대 합격 지원자수 증가
			com_score = score[i].second;	//비교 순위를 업데이트
		}
	}

	return max_num;
}

int main()
{
	int t;	//테스트 케이스 개수
	int n;	//지원자 숫자

	//입력
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << maxRecruit(n) << "\n";
	}
}
