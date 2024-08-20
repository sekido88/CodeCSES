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
int n;
ll a[100005];
int lastPosNumber = 1, res = 0;
multiset<ll>mts;

sekidoCode {
  sp;
  cin >> n;
  FOR(1,n,i) cin >> a[i];
  
 
  
  if (n >= 2) {
    mts.insert(a[1]);
    mts.insert(a[2]);
  }
  
  // if (n >= 3) {
  //   if (a[3] + *mts.begin() <= *mts.rbegin()) {
  //     mts.erase(mts.find(a[lastPosNumber]));
  //     lastPosNumber++;
  //   }
  //   else {
  //     mts.insert(a[3]);
  //     res = 3;
  //   }
  // }
  // for(auto x : mts) {
  //   cout << x << ' ' << '\n' ;
  // }
  FOR(3,n,i) {
    
    if (a[i] + *mts.begin() > *mts.rbegin()) {
      
      mts.insert(a[i]);
      
      int minNumber = *mts.begin();
      mts.erase(mts.begin());
      int minNumber2 = *mts.begin();
      mts.insert(minNumber);
      
      while (!mts.empty() && minNumber2 + minNumber <= *mts.rbegin() && mts.size() >= 2 && lastPosNumber < i) {
        auto it = mts.find(a[lastPosNumber]);
        if (it != mts.end()) {
          mts.erase(it);
        }
        minNumber = *mts.begin();
        mts.erase(mts.begin());
        
        if(!mts.empty()) {  
        int minNumber2 = *mts.begin();
        }
        mts.insert(minNumber);
        lastPosNumber++;
      }
      
      if (mts.size() >= 3) {
        res = max(res, (int)mts.size());
      }
      
    }
    else {
      while (!mts.empty() && mts.size() >= 2 && lastPosNumber < i ) {
        auto it = mts.find(a[lastPosNumber]);
        if (it != mts.end()) {
          mts.erase(it);
        }
        lastPosNumber++;
      }
      mts.insert(a[i]);
    }

  }
  
  cout << res;
}