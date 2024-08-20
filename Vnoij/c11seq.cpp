// sekicode
// 13/15 test
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

int n;
long long a[100005],l,r,s[100005];


sekidoCode {
  sp;
  cin >> n >> l >> r;
  FOR(1,n,i) {
    cin >> a[i];
    s[i] += s[i-1] + a[i];
  }
  
  multiset<ll>mts;
  mts.insert(0);
  ll res = 0 ;
  FOR(1,n,i) {
    
    auto v = mts.upper_bound(s[i] - l);
    auto u = mts.lower_bound(s[i] - r);
    res = res + distance(u,v);
    mts.insert(s[i]);
    
  }
  cout << res;
}
