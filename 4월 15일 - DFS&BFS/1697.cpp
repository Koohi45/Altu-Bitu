#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;   // N, K의 최댓값

int bfs(int n, int k) { 
    vector<int> check(SIZE + 1, 0); //
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;    //수빈이가 동생을 찾는 시간

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n);  //큐에 처음 수빈이의 좌표 저장
    while (!q.empty()) {    //큐가 빌 때 까지
        int x = q.front();  //현재 수빈이의 위치
        q.pop();    //큐에서 제거

        if (x == k) {   //수빈가 동생을 찾으면
            ans = check[x] - 1; //동생 찾는 시간 저장
            break;  //반복문 탈출
        }

        vector<int> child = { x - 1, x + 1, x * 2 }; //자식 노드
        for (int i = 0; i < 3; i++) {   //수빈이가 위치할 수 있는 곳 탐색
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {    //위치가 범위를 벗어나지 않으면서 이미 탐색한 곳이 아니면
                check[child[i]] = check[x] + 1; //시간으로 탐색 표시
                q.push(child[i]);   //다음 탐색을 위해 큐에 추가
            }
        }
    }
    return ans; //시간 리턴
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << bfs(n, k);
    return 0;
}