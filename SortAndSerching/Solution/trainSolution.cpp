/* tim n voi trong tai w tau sao cho so tau la it nhat voi moi thang khach co trong luong la a[i] */ 
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
    int gol = w - 1;
    while (!mts.empty()) {
        gol = gol - * mts.begin() ;
        mts.erase(mts.begin());
        auto it = mts.upper_bound(gol);
        if (it != mts.begin()) {
            --it;
            gol -= *it;
            mts.erase(it);
        } else {
            ans++;
            gol = w - 1;
        }
    }
    
    cout << ans;
    return 0;
}
