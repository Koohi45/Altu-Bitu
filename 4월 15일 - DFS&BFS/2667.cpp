#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//단지 내 집 개수 탐색하는 bfs
int bfs(int n, int r, int c, vector<vector<bool>>& board) {
    int dr[4] = { -1, 1, 0, 0 };    //행에 대하여 상, 하, 좌, 우 검색
    int dc[4] = { 0, 0, -1, 1 };    //열에 대하여 상, 하, 좌, 우 검색

    queue<ci> q;    //탐색에 사용할 큐

    //큐 초기화
    q.push({ r, c });   //현재 위치 저장
    board[r][c] = false;    //방문 체크
    int cnt = 1;    //단지 내 집 수 초기화
    while (!q.empty()) {    //큐가 빌 때 까지
        int cr = q.front().first;   //탐색할 집의 행
        int cc = q.front().second;  //탐색할 집의 열
        q.pop();    //큐에서 제거

        for (int i = 0; i < 4; i++) {   //상하좌우 탐색
            int nr = cr + dr[i];    //상하좌우 행
            int nc = cc + dc[i];    //상하좌우 열
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) { //정사각형 범위를 벗어나거나 이미 방문이 되어있으면
                continue;   //다음 탐색
            }
            q.push({ nr, nc }); //큐에 추가
            board[nr][nc] = false;  //방문 체크
            cnt++;  //단지 내 집 수 증가
        }
    }
    return cnt; //단지 내 집 수 리턴
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>>& board) {
    vector<int> complex;    //단지내 집 수를 저장할 배열
    for (int i = 0; i < n; i++) {   //n행
        for (int j = 0; j < n; j++) {   //n열 탐색
            if (board[i][j]) {  //집이 있다면
                int cnt = bfs(n, i, j, board);  //i행 j열의 집과 연결된 집을 탐색하고 연결된 총 집의 수를 리턴
                complex.push_back(cnt); //한 단지내 집 수를 배열에 추가
            }
        }
    }
    return complex; //배열 리턴
}

/**
 * [단지 번호 붙이기] - bfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    int n;
    string s;

    //입력
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));  //집의 유무 저장할 배열
    for (int i = 0; i < n; i++) {   //n행
        cin >> s;   //한 행 입력
        for (int j = 0; j < n; j++) { //n열
            board[i][j] = s[j] - '0';   //[i][j]에 집의 유무 저장
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board); //단지 내 집 수를 저장한 배열 리턴
    sort(ans.begin(), ans.end());   //오름차순 정렬

    //출력
    cout << ans.size() << '\n'; //총 단지수 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n'; //단지 내 집 수를 출력
    }
    return 0;
}