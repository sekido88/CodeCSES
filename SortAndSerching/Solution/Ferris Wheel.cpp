#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sp ios_base::sync_with_stdio(0);cin.tie(0)
 multiset<int> mts;
int ans = 0 , value ;
int main() {
    sp;
    int n, w;
    cin >> n >> w;
    
    FOR(1, n, i) {
        cin >> value;
        mts.insert(value);
    }
    int gol = w;
    while (!mts.empty()) {
        if (gol - *mts.begin() == 0) {
          ans ++ ;
          mts.erase(mts.begin()) ;
        }
        else {  
          auto it = mts.upper_bound(gol - *mts.begin()) ;
          // cout << "it" <<*it<< ' ' ;
          if (it != mts.begin()) {
            --it;
            if(it != mts.begin()) mts.erase(it) ;
            mts.erase(mts.begin()) ;
            ans ++ ;
          }
          else {
            mts.erase(mts.begin()) ;
            ans ++;
          }
        }
    }
    
    cout << ans;
    return 0;
}
