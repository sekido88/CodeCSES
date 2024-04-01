#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
int a[200005],b[200005],ans = 0 ;
multiset<int>mts;
int main() {
  sp ;
  int m , n , k ;
  cin >> m >> n >> k ;
  FOR(1,m,i) {
    cin >> a[i] ;
  }
  FOR(1,n,i) {
    cin >> b[i] ;
  }
  sort(a + 1 ,a + 1  + m) ;
  sort(b + 1,b + 1 + n);
  int l1 = 1 , l2 = 1 ;
  while(l1 <= m && l2 <= n ) {
    if (b[l2] >= a[l1] - k && b[l2] <= a[l1] + k ) {
      ans ++ ;
      l1 ++ ;
      l2 ++;
    }
    else if(b[l2] < a[l1] - k) {
      l2 ++;
    }
    else l1 ++;
  }
  cout << ans;
}