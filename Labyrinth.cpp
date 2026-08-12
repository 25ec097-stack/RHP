#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
 
const int diff[5] = {0, -1, 0, 1, 0};
string dir = "LURD";
 
void solve() {
    int R, C;
    cin >> R >> C;
    vector<string> g(R);
    int sr, sc;
    for (int row = 0; row < R; row++) {
        cin >> g[row];
        for (int col = 0; col < C; col++) {
            if (g[row][col] == 'A') {
                sr = row;
                sc = col;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    int hops = -1;
    while (!q.empty()) {
        int qsize = q.size();
        hops++;
        while (qsize--) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ar = row + diff[i];
                int ac = col + diff[i + 1];
                if (ar >= 0 && ar < R && ac >= 0 && ac < C) {
                    if (g[ar][ac] == '.') {
                        g[ar][ac] = dir[i];
                        q.push(make_pair(ar, ac));
                    }
                    else if (g[ar][ac] == 'B') {
                        cout << "YES" << endl;
                        cout << hops + 1 << endl;
                        string ans = "";
                        ans += dir[i];
                        while (true) {
                            if (row == sr && col == sc)
                                break;
                            char ch = g[row][col];
                            ans += ch;
                            if (ch == 'L')
                                col++;
                            else if (ch == 'R')
                                col--;
                            else if (ch == 'U')
                                row++;
                            else if (ch == 'D')
                                row--;
                        }
                        reverse(ans.begin(), ans.end());
                        cout << ans << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}
