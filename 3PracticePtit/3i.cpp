// sekicode
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(a,b,i) for(int i = a ; i <= b ; i++)
#define sekidoCode int main()
#define sp ios_base::sync_with_stdio(0);cin.tie(0)

#define p_b(v) push_back(v)

const int mod = 1e9 + 7 ;

vector<bool> checkPrime(1000005,1);
int prime[80000];
int cnt = 0 ;
void snt() {
  
  checkPrime[1] = 0;
  for(long long i = 2 ; i * i<= 1000005 ; i ++) {
    if (checkPrime[i])
      for(long long j = i * i ; j <= 1000005 ; j += i) {
        checkPrime[j] = 0;
      }
  }

  FOR(1,1000005,i) {
    if (checkPrime[i]) prime[++cnt] = i;
  }

}

long long res = 0 ;
sekidoCode {
  
  snt();
  int n ;
  cin >> n ; 
  for(int i = 1 ; i <= cnt ; i++) {
    if (prime[i] >= n) {
      break ;
    }
    auto it  = upper_bound(prime + 1 , prime + 1 + cnt,n - prime[i]) - prime - 1 ;
    if (prime[it] <= prime[i] && prime[i] + prime[it] == n) {
      res ++ ;
    }

  }
  cout << res;
}