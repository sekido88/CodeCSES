#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
vector<pair<ll,ll>>v;
int main() {
  sp ;
  int n ;
  cin >> n;
  FOR(1,n,i) {
    ll x, y ;
    cin >> x >> y;
    v.push_back(make_pair(x,1)) ;
    v.push_back(make_pair(y,-1)) ;
  }
  sort(v.begin(),v.end()) ;
  ll count = 0 ,res = 0 ;
  FOR(0,v.size()-1,i) {
    count += v[i].second ;
    res = max(res,count) ;
  }
  cout<<res;
}