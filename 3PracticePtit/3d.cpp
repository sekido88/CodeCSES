// sekicode
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

#define p_b(v) push_back(v)

const int mod = 1e9 + 7 ;

int n ;
ll m ;
map<ll,ll>mp;
ll res = 0;
ll sum = 0;

sekidoCode {
  cin >> n >> m;
  
  mp[0] = 1;
  for(int i = 1 ; i <= n ; i++) {
    long long x ;
    cin >> x ;
    sum = sum + x ;
    res = res + mp[sum%m] ;
    mp[sum%m] ++;
  }
  cout << res;
}