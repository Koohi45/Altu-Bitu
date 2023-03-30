#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

ll minCost(priority_queue<ll, vector<ll>, greater<>> &pq){
  ll sum = 0;
  ll ans = 0;
  
  while(pq.size() > 1){
    sum = pq.top();
    pq.pop();
    sum += pq.top();
    pq.pop();
    pq.push(sum);
    ans += sum;
  }

  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t, k, file_size;

  cin >> t;
  while(t--){
    priority_queue<ll, vector<ll>, greater<>> pq;

    cin >> k;
    for(int i = 0; i < k; i++){
      cin >> file_size;
      pq.push(file_size);
    }

    cout << minCost(pq) << '\n';
  }
  return 0;
}