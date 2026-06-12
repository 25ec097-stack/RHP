#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int dp[s2.length() + 1][s1.length() + 1];

    for(int row = 0; row <= s2.length(); row++) {
        dp[row][0] = 0;
    }

    for(int col = 0; col <= s1.length(); col++) {
        dp[0][col] = 0;
    }

    for(int row = 1; row <= s2.length(); row++) {
        for(int col = 1; col <= s1.length(); col++) {

            if(s1[col - 1] == s2[row - 1]) {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }
            else {
                dp[row][col] = max(dp[row - 1][col],
                                   dp[row][col - 1]);
            }
        }
    }

    cout << "DP Matrix:" << endl;

    for(int row = 0; row <= s2.length(); row++) {
        for(int col = 0; col <= s1.length(); col++) {
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Length = " << dp[s2.length()][s1.length()];

    return 0;
}