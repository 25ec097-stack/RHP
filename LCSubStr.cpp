#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int m = str1.length();
    int n = str2.length();

    int dp[n + 1][m + 1] = {0};

    int maxLen = 0;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {

            if (str1[col - 1] == str2[row - 1]) {
                dp[row][col] = dp[row - 1][col - 1] + 1;

                if (dp[row][col] > maxLen)
                    maxLen = dp[row][col];
            }
            else {
                dp[row][col] = 0;
            }
        }
    }

    // Print DP Matrix
    for (int row = 0; row <= n; row++) {
        for (int col = 0; col <= m; col++) {
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    cout << "Length = " << maxLen;

    return 0;
}