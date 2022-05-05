#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;   //인접 리스트
vector<int> parent; //부모 노드 저장할 배열

void dfs_recursion(int prev, int curr) {    
    if (parent[curr]) {  //부모 노드가 저장되어 있으면
        return; //종료
    }
    parent[curr] = prev; //부모 노드 저장   
    for (int i = 0; i < adj_list[curr].size(); i++) {   //노드 curr과 인접한 노드를 탐색
        dfs_recursion(curr, adj_list[curr][i]); //dfs 탐색
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {
    int n, a, b;

    //입력
    cin >> n;
    adj_list.assign(n + 1, vector<int>(0)); //인접 리스트 n + 1행
    parent.assign(n + 1, 0);    //부모 노드 배열 n + 1 크기 지정, 0으로 초기화
    for (int i = 1; i < n; i++) {   //1 ~ n - 1행
        cin >> a >> b;  //입력
        adj_list[a].push_back(b);   //노드 a와 연결된 노드 b
        adj_list[b].push_back(a);   //노드 b와 연결된 노드 a 추가
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';  //부모 노드 출력
    }
    return 0;
}