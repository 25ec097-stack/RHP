#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        vector<int> pa(n + 1, 0), pb(m + 1, 0);
        for (int i = 1; i <= n; i++)
            pa[i] = (pa[i - 1] + (a[i - 1] - '0')) % 10;
        for (int j = 1; j <= m; j++)
            pb[j] = (pb[j - 1] + (b[j - 1] - '0')) % 10;
        if (pa[n] != pb[m]) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> dp(m + 1, 1);
        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (pa[i] == pb[j])
                    dp[j] = max(dp[j], prev + 1);
                dp[j] = max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        cout << dp[m] - 1 << '\n';
    }
    return 0;
}
