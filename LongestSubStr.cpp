#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        if(arr[i] == 0)
            arr[i] = -1;
    }

    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;

        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum == 0) {
                int len = j - i + 1;

                if(len > maxLen)
                    maxLen = len;
            }
        }
    }

    cout << maxLen;

    return 0;
}