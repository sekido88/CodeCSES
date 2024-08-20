#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int N, M, K;
    cin >> N >> M ;

    vector<pair<int, int>> A(N), B(M);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].first >> A[i].second;
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i].first >> B[i].second;
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));
    dp[0][0] = 0;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i > 0) {
                int dx = A[i-1].first - (j > 0 ? B[j-1].first : 0);
                int dy = A[i-1].second - (j > 0 ? B[j-1].second : 0);
                dp[i][j] = min(dp[i][j], dp[i-1][j] + dx * dx + dy * dy);
            }
            if (j > 0) {
                int dx = B[j-1].first - (i > 0 ? A[i-1].first : 0);
                int dy = B[j-1].second - (i > 0 ? A[i-1].second : 0);
                dp[i][j] = min(dp[i][j], dp[i][j-1] + dx * dx + dy * dy);
            }
            if (i > 0 && j > 0) {
                int dx = A[i-1].first - B[j-1].first;
                int dy = A[i-1].second - B[j-1].second;
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + dx * dx + dy * dy);
            }
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}
