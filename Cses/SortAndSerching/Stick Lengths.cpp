#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
ll a[200005] ,maxValue = LONG_MIN,minValue = LONG_MAX , ans = LONG_MAX;

int n ;
ll FindCost(ll value) {
  ll s = 0 ;
  FOR(1,n,i) s = s + abs(a[i] - value) ;
  return s;
}
void solve() {
ll l = minValue ,r = maxValue;
  while(l <= r) {
    ll m = (ll) ( l + r) / 2 ;
    ll cost = FindCost(m) ;
    if (cost <= ans) {
      ans = cost ;
      l = m + 1;
    }
    else {
     
      r = m - 1 ;
    }

  }
  cout << ans;
}
int main(){
  sp ;
  cin >> n ; 
  FOR(1,n,i) {
    cin >> a[i] ;
    maxValue = max(maxValue,a[i]) ;
    minValue = min(minValue,a[i]) ;
  }
  solve() ;
	return 0;
}