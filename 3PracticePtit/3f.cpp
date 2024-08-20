#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const ll MOD = 1e12; // Giới hạn tối đa của M là 10^12

// Ma trận 2x2 nhân ma trận 2x2
matrix matMul(matrix A, matrix B, ll mod) {
    matrix C(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            C[i][j] = (A[i][0] * B[0][j] + A[i][1] * B[1][j]) % mod;
    return C;
}

// Lũy thừa ma trận
matrix matPow(matrix A, ll p, ll mod) {
    if (p == 1) return A;
    if (p % 2) return matMul(A, matPow(A, p - 1, mod), mod);
    matrix X = matPow(A, p / 2, mod);
    return matMul(X, X, mod);
}

// Tính Fibonacci modulo
ll fib(ll n, ll mod) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    matrix F = {{1, 1}, {1, 0}};
    F = matPow(F, n - 1, mod);
    return F[0][0];
}

// Hàm tính GCD
ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, M;
        cin >> a >> b >> M;
        ll gcd_ab = gcd(a, b);
        ll result = fib(gcd_ab, M);
        cout << result << endl;
    }
    return 0;
}
