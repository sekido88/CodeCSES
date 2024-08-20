#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

const int MAXN = 100005;
int n;
ll a[MAXN];
int res = 0;

bool isTriangle(ll x, ll y, ll z) {
    return x + y > z ;
}

sekidoCode {
    sp;
    cin >> n;
    FOR(1, n, i) cin >> a[i];

    int left = 1, right = 1;
    multiset<ll> window;

    while (right <= n) {
        window.insert(a[right]);

        while (window.size() >= 3) {
            bool valid = true;
            auto it1 = window.begin();
            auto it2 = next(it1);
        

            if (!isTriangle(*it1, *it2, *window.rbegin())) {
                valid = false;
            }

            if (valid) {
                res = max(res, right - left + 1);
                break;
            }

            window.erase(window.find(a[left]));
            left++;
        }

        right++;
    }

    cout << res;
}