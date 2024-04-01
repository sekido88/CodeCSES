#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
int a[200005] ,ans = 0;
int main() {
    sp;
    int n, w;
    cin >> n >> w;
    FOR(1, n, i) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n) ;
    int l = 1, r = n;
    while (l <= r) {
      if (a[l] == w) {
        l++;
        
      }
      if (a[l] + a[r] <= w) {
        ans ++ ;
        l++;
        r--;
      }
      else if(a[l] + a[r] > w) {
        r--;
        ans++;
      }
    }
    cout<<ans ;
    
    return 0;
}
