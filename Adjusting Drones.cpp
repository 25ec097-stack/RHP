#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    long long sum;
    long long pref;
};
struct SegmentTree {
    int n;
    vector<Node> tree;
    vector<int> lazy;
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 5);
        lazy.assign(4 * n + 5, -1);
    }
    Node merge(Node a, Node b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.pref = max(a.pref, a.sum + b.pref);
        return res;
    }
    void apply(int v, int l, int r, int value) {
        tree[v].sum = 1LL * (r - l + 1) * value;
        tree[v].pref = max(0LL, tree[v].sum);
        lazy[v] = value;
    }
    void push(int v, int l, int r) {
        if (lazy[v] == -1 || l == r)
            return;
        int mid = (l + r) / 2;
        apply(v * 2, l, mid, lazy[v]);
        apply(v * 2 + 1, mid + 1, r, lazy[v]);
        lazy[v] = -1;
    }
    void build(int v, int l, int r) {
        if (l == r) {
            tree[v] = {0, 0};
            return;
        }
        int mid = (l + r) / 2;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid + 1, r);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    void update(int v, int l, int r,
                int ql, int qr, int value) {
        if (ql <= l && r <= qr) {
            apply(v, l, r, value);
            return;
        }
        push(v, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update(v * 2, l, mid, ql, qr, value);
        if (qr > mid)
            update(v * 2 + 1, mid + 1, r, ql, qr, value);
        tree[v] = merge(tree[v * 2], tree[v * 2 + 1]);
    }
    void update(int l, int r, int value) {
        if (l > r)
            return;
        update(1, 1, n, l, r, value);
    }
    int findFirst(int v, int l, int r, int ql, long long &need) {
        if (r < ql || tree[v].pref < need)
            return -1;
        if (l == r)
            return l;
        push(v, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            int res = findFirst(v * 2,l,mid,ql,need);
            if (res != -1)
                return res;
            need -= tree[v * 2].sum;
        }
        return findFirst(v * 2 + 1,mid + 1,r,ql,need);
    }
    int findFirst(int ql, long long need) {
        return findFirst(1, 1, n, ql, need);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(3 * n + 10, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int M = 3 * n + 5;
    SegmentTree st(M);
    st.build(1, 1, M);
    st.update(2 * n + 1, 3 * n + 1, 1);
    int answer = 0;
    for (int i = 2 * n; i >= 1; i--) {
        if (cnt[i] <= k) {
            st.update(i, i, 1 - cnt[i]);
        }
        else {
            long long need = cnt[i] - k;
            int j = st.findFirst(i + 1, need);
            answer = max(answer, j - i);
            st.update(i, j - 1, 0);
            st.update(j, j, 1 - k);
        }
    }
    cout << answer << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}