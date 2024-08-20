// sekicode
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

#define p_b(v) push_back(v)

const int mod = 1e9 + 7 ;
vector<int>dpMax(1000005,0);
vector<int>dpMin(1000005,INT_MAX);
vector<int>a(1000005 + 1);
sekidoCode {
    int n;
    cin >> n;

    FOR(1,n,i) {
      cin >> a[i];
      dpMax[i] = max(dpMax[i-1],a[i]);
    }
    for(int i = n ; i >= 1 ; i--) {
      dpMin[i] = min(dpMin[i + 1],a[i]);
    }
    vector<int>res;
    dpMin[0] = 0 ;
    dpMax[n + 1] = INT_MAX;
    for(int i = 1 ;i <= n ;i++) {
      if (a[i] > dpMin[i - 1] && a[i] < dpMax [i + 1]) {
        res.push_back(a[i]);    
      }
    }
    cout << res.size() <<' ';
    for(auto x : res ) cout << x << ' ';
}