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
ll n, k;
long long a[105];

double mu2(double x) {
    return (double)(x * x);
}

double f(double x) {
    double kq = 0.0;
    FOR(1,n,i) {
        kq += mu2(abs(a[i] - x));
    }
    // cout << kq << '\n';
    return kq;
}

long long res = 0;

void tknp(double l,double r) {
    for (int it = 1; it <= 10000; it++)  {
        double x1 = l + (r - l) / 3.0;
        double x2 = r - (r - l) / 3.0;
      
        if(f(x1) > f(x2)) {
            l = x1;
        }
        else {
            r = x2;
        }
    }
    // res = f((l + r) / 2.0);
    cout << fixed << setprecision(2) << f(l);
  
}

void solve() {
    FOR(1,n,i) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    
    if (k == 1) {
        long long d = a[n / 2 + 1];
        // long long d1 = a[(n + 1) / 2 - 1];
        FOR(1,n,i) {
            res += abs(a[i] - d);
        }
        cout << fixed << setprecision(2) <<(double) res;
    } 
    else {
        tknp(a[1], a[n]);
    }
}

sekidoCode {
    sp;
    cin >> n >> k;
    solve();
}
