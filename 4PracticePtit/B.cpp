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
ll n,k;

long long solve() {
  long long res = 1;
  for(long long i = 1 ; i * i <= k ;i++){
    if (k % i == 0 ) {
      if (k / i >= n) {
        res = max(res,i);
      }
      if (k/(k/i) >= n) {
        res = max(res,k/i);
      }
    }
  }
  cout << res;
}

sekidoCode {
  
  sp;
  cin >> n >> k;
  solve();
    
}
