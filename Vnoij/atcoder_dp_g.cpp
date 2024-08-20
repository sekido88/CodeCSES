// sekicode
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

#define p_b(v) push_back(v)
#define fi first 
#define se second

const int mod = 1e9 + 7 ;

bool visited[100005];
vector<int>adj[100005];
long long dp[100005];
int n,m;
long long res = 0;

long long dfs(int u) {
  if (dp[u]) return dp[u];
  
  for(auto x : adj[u]) {
    dp[x] = dfs(x);
    dp[u] = max(dp[x] + 1, dp[u]);
  }
  
  // cout << dp[u] << '\n';
  return dp[u];
}

sekidoCode {
  sp;
  cin >> n >> m;
  FOR(1,m,i) {
    int x,y;
    cin >> x >> y;
    adj[x].push_back(y);
  }
  FOR(1,n,i) {
    dfs(i);
  }
  FOR(1,n,i) {
    // cout << dp[i] << ' ';
    res = max(res,dp[i]);
  }
  cout << res;
}
