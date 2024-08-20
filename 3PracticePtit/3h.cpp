#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 8;

int a[N], l[N], r[N];

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void build(int node, int start, int end, int arr[]) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid, arr);
            build(2 * node + 1, mid + 1, end, arr);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // return a value that does not affect the max query
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_query = query(2 * node, start, mid, l, r);
        int right_query = query(2 * node + 1, mid + 1, end, l, r);
        return max(left_query, right_query);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    SegmentTree segTree(n);
    segTree.build(1, 1, n, a);

    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        l[i] = !s.empty() ? s.top() : 0;
        s.push(i);
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        r[i] = !s.empty() ? s.top() : n + 1;
        s.push(i);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] > 0) {
            int j = l[i];
            int x = l[j] + 1, y = j - 1, k = j;
            while (x <= y) {
                int m = (x + y) / 2;
                if (segTree.query(1, 1, n, m, j - 1) <= a[i]) {
                    k = m;
                    y = m - 1;
                } else {
                    x = m + 1;
                }
            }
            res += (ll)(j - k + 1) * (r[i] - i) * a[i];
        }
        if (r[i] <= n) {
            int j = r[i];
            int x = j + 1, y = r[j] - 1, k = j;
            while (x <= y) {
                int m = (x + y) / 2;
                if (segTree.query(1, 1, n, j + 1, m) <= a[i]) {
                    k = m;
                    x = m + 1;
                } else {
                    y = m - 1;
                }
            }
            res += (ll)(k - j + 1) * (i - l[i]) * a[i];
        }
    }
    printf("%lld", res);
}
