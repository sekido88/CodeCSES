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
const long long INF = LONG_MAX;

struct Node {
  long long lazy;
  long long val;
} nodes[400005];

void down(int id) {
  long long t = nodes[id].lazy;
  nodes[id * 2 ].lazy += t;
  nodes[id * 2 ].val += t;
  
  nodes[id * 2 + 1].lazy += t;
  nodes[id * 2 + 1].val += t;
  
  nodes[id].lazy = 0;
  
}
void update(int id,int l,int r,int u, int v,long long value) {
  if (v < l || r < u) {
    return;
  }
  if (u <= l && r <= v) {
    nodes[id].val += value;
    nodes[id].lazy += value;
    return ;
  }
  int m = (l + r) / 2;
  down(id);
  
  update(id * 2,l,m,u,v,value);
  update(id * 2 + 1,m + 1,r,u,v,value);
  nodes[id].val = max(nodes[id * 2].val,nodes[id * 2 + 1].val);
}
long long get(int id ,int l ,int r,int u ,long long v) {
  if (r < u || v < l) {
    return -INF;
  }
  if (u <= l && r <= v) {
    return nodes[id].val;
  }
  int m = (l + r) / 2;
  down(id);
  
  return max(get(id * 2,l,m,u,v),get(id * 2 + 1,m + 1,r,u,v));
}
int a[200005];
sekidoCode {
  int n;
  cin >> n;
  FOR(1,n,i) {
    cin >> a[i];
    update(1,1,n,i,i,a[i]);
  }
  
  int t;
  cin >> t;
  while(t--) {
    long long x,l,r,val;;
    cin >> x;
    if (x == 1) {
    
      cin >> l >> r >> val;
      update(1,1,n,l,r,val);
    }
    else {
 
      cin >> l >> r;
      cout << get(1,1,n,l,r) << '\n';
    }
  }
  
}