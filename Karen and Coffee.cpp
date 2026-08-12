#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k, q;
    cin >> n >> k >> q;
 
    const int MAX = 200000;
    vector<int> diff(MAX + 2, 0);
 
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }
 
    vector<int> cnt(MAX + 1, 0);
    cnt[1] = diff[1];
 
    for (int i = 2; i <= MAX; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }
 
    vector<int> pre(MAX + 1, 0);
 
    for (int i = 1; i <= MAX; i++) {
        pre[i] = pre[i - 1];
        if (cnt[i] >= k)
            pre[i]++;
    }
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << '\n';
    }
 
    return 0;
}
