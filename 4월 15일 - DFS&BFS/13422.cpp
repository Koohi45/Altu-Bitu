#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int>& house) {
    //윈도우 초기화
    int money = 0;  //훔친 돈
    for (int i = 0; i < m; i++) {   //0 ~ m - 1까지의 집
        money += house[i];  //훔친 돈 더하기
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; //1 리턴
    }
    for (int i = m; i < n + m - 1; i++) {   //윈도우 슬라이드의 끝점 i
        money -= house[i - m];  //이전 윈도우의 첫번째 집 제거
        money += house[i % n];  //현재 윈도우에 마지막 집 추가
        if (money < k) {    //훔친 돈이 자동 방범 장치가 작동하는 최소 돈보다 적다면
            ans++;  //경우의 수 하나 증가
        }
    }
    return ans; //경우의 수 리턴
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k;

    cin >> t;   //테스트 케이스 수 입력
    while (t--) {   
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0);    //n개의 집
        for (int i = 0; i < n; i++) {   //0 ~ n - 1개의 집
            cin >> house[i];    //각 집에 보관되는 돈 입력
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}