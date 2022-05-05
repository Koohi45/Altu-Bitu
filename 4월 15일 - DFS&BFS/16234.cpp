#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited; //board 나라 인구수, visited 나라 탐색 체크
queue<ci> countries;    //인구이동이 가능한 나라의 좌표 저장할 큐


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci>& union_cord) {
    for (int i = 0; i < union_cord.size(); i++) {   //연합에 참가한 나라 수만큼
        int row = union_cord[i].first, col = union_cord[i].second;  //나라 위치
        board[row][col] = population;   //인구 수 저장
        countries.push({ row, col }); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = { -1, 1, 0, 0 };    //한 나라의 상하좌우에 있는 나라 탐색을 위해
    int dc[4] = { 0, 0, -1, 1 };

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({ cr, cc });   //현재 나라 저장
    queue<ci> q;    //bfs 탐색에 사용할 큐
    q.push({ cr, cc }); //현재 나라 위치 저장
    int sum = board[cr][cc], cnt = 1;   //연합하는 나라의 인구 수와 연합하는 나라의 수 저장
    while (!q.empty()) {    //큐가 빌 때까지
        cr = q.front().first;   //나라 위치 행
        cc = q.front().second;  //나라 위치 열
        q.pop();    //큐에서 제거

        for (int i = 0; i < 4; i++) {   //상하좌우 검색
            int nr = cr + dr[i];    //cr + dr[i]을 더한 행
            int nc = cc + dc[i];    //cc + dc[i]을 더한 열의 나라를 탐색
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) { //nxn 크기를 벗어나거나 이미 탐색한 나라라면
                continue;   //다음 실행
            }
            int diff = abs(board[nr][nc] - board[cr][cc]);  //나라 사이의 인구 수 차이
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({ nr, nc }); //큐에 저장
                visited[nr][nc] = day;  //탐색 체크
                union_cord.push_back({ nr, nc }); //연합에 추가
                sum += board[nr][nc];   //추가한 나라의 인구 수를 더함
                cnt++;  //연합에 추가한 나라의 수 하나 증가
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true;    //인구 이동이 있음을 리턴
    }
    return false;   //연합하는 나라가 없으면 인구이동 종료
}

int simulation(int n, int l, int r) {
    int day = 0; //방문 체크로도 사용
    while (true) {
        day++;  //하루 증가
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) {    //나라 하나 탐색
            int row = countries.front().first;  //나라 위치 행
            int col = countries.front().second; //나라 위치 열
            countries.pop();    //큐에서 제거
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue;   //다음 나라 탐색을 위해 continue
            }
            visited[row][col] = day;    //탐색 체크
            if (bfs(n, l, r, row, col, day)) {  //bfs 탐색
                is_move = true; //인구 이동
            }
        }
        if (!is_move) { //인구 이동 종료
            return day - 1; //day에 인구 이동이 종료되었으므로 day - 1까지 인구이동이 있었음
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {
    int n, l, r;    

    //입력
    cin >> n >> l >> r;
    board.assign(n, vector<int>(n, 0));     //board 크기 n지정
    visited.assign(n, vector<int>(n, 0));   //visited 크기 n 지정
    for (int i = 0; i < n; i++) {       //0 ~ n - 1행
        for (int j = 0; j < n; j++) {   //0 ~ n - 1열
            cin >> board[i][j];         //입력 받아 board[i][j]에 저장
            countries.push({ i, j });   //모든 나라의 좌표를 큐에 저장
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);
    return 0;
}