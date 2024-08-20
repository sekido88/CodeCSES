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
int t[200000];


void update(int id ,int l ,int r , int pos,int value) {
  if (l == pos && r == pos) {
    t[id] = max(t[id],value);
    return ;
  }
  if (l > pos || r < pos) {
    return ;
  }
  int m = (l + r) /2;
  update(id * 2,l,m,pos,value);
  update(id * 2 + 1,m + 1,r,pos,value);
  t[id] = max(t[id * 2], t[id * 2 + 1]);
}
long long get(int id , int l,int r,int u ,int v) {

  if (u <= l && r <= v) {
    return  t[id];
  }
  
    if ( l > v || r < u) {
    return 0;
  }
  
  int m = (l + r) /2;
  return(max(get(id * 2,l,m,u,v),get(id * 2 + 1,m + 1,r,u,v)));
}
long long a[30005],b[30005];
sekidoCode {
    int n ;
    cin >> n;
    FOR(1,n,i) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    FOR(1,n,i) {
      b[i] = lower_bound(a + 1,a + 1 + n,b[i]) - a;
    }
    long long res = 0;
    FOR(1,n,i) {
        long long len = get(1,1,n,1,b[i] - 1);
        res = max(res,len + 1);
        update(1,1,n,b[i],len + 1);
    }
    cout << res;
}