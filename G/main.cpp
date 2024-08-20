// sekicode
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

#define p_b(v) push_back(v)

const int mod = 1e9 + 7 ;
const int max_v = INT_MAX;

vector<int>g[100005];
int way[100005] , n;
bool visited[100005] ;

void bfs(int u) {
  queue<int>q;
  q.push(u);
  way[1] = 0 ;
  while(!q.empty()) {
    int x = q.front() ;
    visited[x] = 1 ;
    for(auto value : g[x]) {
      if (!visited[value]) {
        q.push(value);
        if (way[value] == 0)
          way[value] = x;
      }
    }
    q.pop();
  }

  int tmp = n ;
  bool ok = 0 ;
  int cnt = 1 ;
  stack<int> s ;
  s.push(n);

  while (way[tmp] != 0) {
    cnt ++ ;
    s.push(way[tmp]);
    tmp = way[tmp];
    if (tmp == 1) {
      ok = 1;
    }
  }

  if (ok) {
    cout << cnt << '\n' ;
    while(!s.empty()) {
      cout << s.top() << ' ';
      s.pop();
    }
  }
  else {
    cout << "IMPOSSIBLE";
  }

}

sekidoCode {

  int m , x, y;
  freopen("in.text","r",stdin);
    freopen("out.text","w",stdout);

  cin >> n >> m;
  FOR(1,m,i) {
    cin >> x >> y ;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bfs(1);

}
