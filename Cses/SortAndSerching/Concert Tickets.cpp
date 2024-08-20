#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
  int m , n  ;
  multiset<ll>a;
  ll x , res ;
  int main() 
  {
      sp ;
      cin >> m  >> n ;
      for(int i = 1 ; i <= m ; i++) {
        cin >> x ;
        a.insert(x) ;
      }
      while(n--) {
        cin >> x ;
        res = -1 ;
        multiset<ll>::iterator it = a.upper_bound(x) ;
        if (it != a.begin()) {
           --it ;
          res = *it ;
          a.erase(it) ;
        }
        cout<<res<<'\n' ;
      }
      return 0;
  }