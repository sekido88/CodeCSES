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
int n,k;
int a[200005];
sekidoCode {
  

  multiset<ll>mts;
  sp;
  cin >> n >> k;
  FOR(1,n,i) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  FOR(1,k,i) mts.insert(a[i]);
  // auto rit = mts.rbegin();
  
  ll res = *mts.rbegin() - *mts.begin();
  FOR(k + 1 , n ,i) {
    mts.erase(mts.begin());
    mts.insert(a[i]);
    res = min (res , (*mts.rbegin()) - (*mts.begin()));
    // cout << res << ' ';
  }
  // 10 11 15
  // 11 14 15
  // 12 14 15
  cout << res;
  
    
}
