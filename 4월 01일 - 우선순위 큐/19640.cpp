#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct info{
  int line, order, day, hurry;
  //idx: 줄번호
};

struct cmp{
  bool operator() (const info &x1, const info &x2){
    /* 
    1. 근무일 수 가장 크면 우선순위  
    2. 급한 정도가 크면 우선순위
    3. 줄 번호가 작으면 우선순위 
    */
    if(x1.day != x2.day){
      return x2.day > x1.day;
    }
    if(x1.hurry != x2.hurry){
      return x2.hurry > x1.hurry;
    }
    return x2.line < x1.line;
  }
};

int toiletCnt(vector<queue<info>> &toilet_line, int n, int m, int k){
  int ans = 0;
  priority_queue<info, vector<info>, cmp> pq;

  // 각 줄에 맨 앞사람을 우선순위 큐에 삽입
  for(int i = 0; i < m; i++){
    if(!toilet_line[i].empty()){
      pq.push(toilet_line[i].front());
      toilet_line[i].pop();
    }
  }

  // 우선순위대로 화장실 사용
  while(pq.top().order != k){
    info man = pq.top();
    pq.pop();
    if(!toilet_line[man.line].empty()){
      pq.push(toilet_line[man.line].front());
      toilet_line[man.line].pop();
    }
    ans++;
  }

  return ans;
}

int main(){
  int n, m, k, d, h;
  
  cin >> n >> m >> k;
  vector<queue<info>> toilet_line(m);
  for(int i = 0; i < n; i++){
    cin >> d >> h;
    toilet_line[i % m].push({i % m, i, d, h});
  }

  cout << toiletCnt(toilet_line, n, m, k);
  return 0;
}